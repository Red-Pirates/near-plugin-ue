import * as blockchain from '../utils/blockchain';
import { Account } from 'near-api-js';
import { formatNearAmount } from 'near-api-js/lib/utils/format';
import { FTBalanceResponse, NearFTMetadata } from '../models/FT';

class ftService {
  getFTBalance = async (
    accountId: string,
    contractId: string,
    account?: Account,
  ): Promise<FTBalanceResponse> => {
    const ftBalance = await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId,
      'ft_balance_of',
      { account_id: accountId },
    );
    const ftMeta = await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId,
      'ft_metadata',
      {},
    );
    return {
      tokenName: ftMeta.name,
      symbol: ftMeta.symbol,
      icon: ftMeta.icon,
      balance: formatNearAmount(ftBalance),
    };
  };

  getFTTotalBalance = async (contractId: string, account?: Account): Promise<FTBalanceResponse> => {
    const ftBalance: string = await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId,
      'ft_total_supply',
      {},
    );
    const ftMeta: NearFTMetadata = await blockchain.viewContractFunction(
      account || blockchain.masterAccount,
      contractId,
      'ft_metadata',
      {},
    );
    return {
      tokenName: ftMeta.name,
      symbol: ftMeta.symbol,
      icon: ftMeta.icon,
      balance: formatNearAmount(ftBalance),
    };
  };
}

export const FTService = new ftService();
