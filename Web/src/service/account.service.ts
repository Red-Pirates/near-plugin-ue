import * as blockchain from '../utils/blockchain';
import { formatNearAmount } from 'near-api-js/lib/utils/format';
import { KeyPair } from 'near-api-js';
import config from '../config';
import { NearNFTStruct, NFTResponse } from '../models/NFT';
import { FTBalanceResponse } from '../models/FT';

class UserAccountService {
  getAccountBalance = async (accountId: string) => {
    const account = await blockchain.near.account(accountId);
    const balance = await account.getAccountBalance();
    return {
      total: formatNearAmount(balance.total),
      stateStaked: formatNearAmount(balance.stateStaked),
      staked: formatNearAmount(balance.staked),
      available: formatNearAmount(balance.available),
    };
  };

  createAccount = async (name: string, amount?: string) => {
    const keyPair = KeyPair.fromRandom('ed25519');
    const newAccountId = `${name}.${config.CONTRACT_NAME}`;
    await blockchain.masterAccount.createAccount(
      newAccountId,
      keyPair.getPublicKey().toString(),
      amount || '1000000000000000000000000',
    );
    return {
      accountId: newAccountId,
      publicKey: keyPair.getPublicKey().toString(),
    };
  };

  getNFTTokens = async (
    accountId: string,
    contractId: string,
    fromIndex?: string,
    limit?: number,
  ) => {
    const tokens: NearNFTStruct[] = await blockchain.masterAccount.viewFunction(
      contractId,
      'nft_tokens_for_owner',
      {
        account_id: accountId,
        from_index: fromIndex,
        limit: Number(limit),
      },
    );
    return tokens.map((token) => this.castNearNFTStructToResponse(token));
  };

  getNFTSupply = async (accountId: string, contractId: string) => {
    return await blockchain.masterAccount.viewFunction(contractId, 'nft_supply_for_owner', {
      account_id: accountId,
    });
  };

  getFTBalance = async (accountId: string, contractId: string): Promise<FTBalanceResponse> => {
    const ftBalance = await blockchain.masterAccount.viewFunction(contractId, 'ft_balance_of', {
      account_id: accountId,
    });
    const ftMeta = await blockchain.masterAccount.viewFunction(contractId, 'ft_metadata', {});
    return {
      tokenName: ftMeta.name,
      symbol: ftMeta.symbol,
      icon: ftMeta.icon,
      balance: formatNearAmount(ftBalance),
    };
  };

  private castNearNFTStructToResponse = (token: NearNFTStruct): NFTResponse => {
    return {
      tokenId: token.token_id,
      ownerId: token.owner_id,
      title: token.metadata.title,
      description: token.metadata.description,
      media: token.metadata.media,
      mediaHash: token.metadata.media_hash,
      copies: token.metadata.copies,
      issuedAt: token.metadata.issued_at,
      expiresAt: token.metadata.expires_at,
      startsAt: token.metadata.starts_at,
      updatedAt: token.metadata.updated_at,
      extra: token.metadata.extra,
      reference: token.metadata.reference,
      referenceHash: token.metadata.reference_hash,
    };
  };
}

export const userAccountService = new UserAccountService();
