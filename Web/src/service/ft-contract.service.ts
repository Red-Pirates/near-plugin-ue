import { FtBalanceResponse, FtMetadata } from '../models/FT';
import { near } from '../utils/blockchain';
import { formatNearAmount } from 'near-api-js/lib/utils/format';
import { keysToCamel } from '../utils/snakeToCamelCase';

class FtContractService {
  getFtTotalSupply = async (contractId: string): Promise<FtBalanceResponse> => {
    const account = await near.account(contractId);
    const totalSupply = await account.viewFunction(contractId, 'ft_total_supply', {});
    return { balance: formatNearAmount(totalSupply) };
  };

  getFtBalance = async (accountId: string, contractId: string): Promise<FtBalanceResponse> => {
    const account = await near.account(contractId);
    const ftBalance = await account.viewFunction(contractId, 'ft_balance_of', {
      account_id: accountId,
    });
    return { balance: formatNearAmount(ftBalance) };
  };

  getFtMeta = async (contractId: string): Promise<FtMetadata> => {
    const account = await near.account(contractId);
    const ftMeta = await account.viewFunction(contractId, 'ft_metadata', {});
    return keysToCamel(ftMeta);
  };
}

export const ftContractService = new FtContractService();
