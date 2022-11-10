import { NearNFTStruct } from '../models/NFT';
import { keysToCamel } from '../utils/snakeToCamelCase';
import { near } from '../utils/blockchain';

class NftService {
  getNftTotalSupply = async (contractId: string) => {
    const account = await near.account(contractId);
    const nftSupply = await account.viewFunction(contractId, 'nft_total_supply', {});
    return { nftSupply };
  };

  getNftTokens = async (contractId: string, fromIndex?: string, limit?: number) => {
    const account = await near.account(contractId);
    const tokens: NearNFTStruct[] = await account.viewFunction(contractId, 'nft_tokens', {
      from_index: fromIndex,
      limit: Number(limit),
    });
    return { nftTokens: tokens.map((token) => keysToCamel(token)) };
  };

  getNftMetadata = async (contractId: string) => {
    const account = await near.account(contractId);
    const nftMetadata = await account.viewFunction(contractId, 'nft_metadata', {});
    return keysToCamel(nftMetadata);
  };

  getNftToken = async (contractId: string, tokenId: string) => {
    const account = await near.account(contractId);
    const nftToken = await account.viewFunction(contractId, 'nft_token', {
      token_id: tokenId,
    });
    return keysToCamel(nftToken);
  };

  getNftTokensForOwner = async (
    accountId: string,
    contractId: string,
    fromIndex?: string,
    limit?: number,
  ) => {
    const account = await near.account(contractId);
    const tokens: NearNFTStruct[] = await account.viewFunction(contractId, 'nft_tokens_for_owner', {
      account_id: accountId,
      from_index: fromIndex,
      limit: Number(limit),
    });
    return { accountNftTokens: tokens.map((token) => keysToCamel(token)) };
  };

  getNftSupplyForOwner = async (accountId: string, contractId: string) => {
    const account = await near.account(contractId);
    const nftSupply = await account.viewFunction(contractId, 'nft_supply_for_owner', {
      account_id: accountId,
    });
    return { nftSupply };
  };
}

export const nftService = new NftService();
