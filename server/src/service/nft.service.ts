import * as blockchain from '../utils/blockchain';
import { Account } from 'near-api-js';
import { NearNFTStruct, NFTResponse } from '../models/NFT';

class NftService {
  getToken = async (tokenId: string, contractId?: string, account?: Account) => {
    const token: NearNFTStruct = await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId || 'x.paras.near',
      'nft_token',
      { token_id: tokenId },
    );
    return this.castNearNFTStructToResponse(token);
  };

  getNFTTokens = async (
    accountId: string,
    contractId: string,
    fromIndex?: string,
    limit?: number,
    account?: Account,
  ) => {
    const tokens: NearNFTStruct[] = await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId || 'x.paras.near',
      'nft_tokens_for_owner',
      {
        account_id: accountId,
        from_index: fromIndex,
        limit: Number(limit),
      },
    );
    return tokens.map((token) => this.castNearNFTStructToResponse(token));
  };

  getNFTSupply = async (accountId: string, contractId?: string, account?: Account) => {
    return await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId || 'x.paras.near',
      'nft_supply_for_owner',
      { account_id: accountId },
    );
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

export const nftService = new NftService();
