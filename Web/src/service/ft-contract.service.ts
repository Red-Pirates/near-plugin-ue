import { FtBalanceResponse, FtMetadata, FtTotalSupplyResponse } from '../models/FT';
import * as blockchain from '../utils/blockchain';
import { formatNearAmount } from 'near-api-js/lib/utils/format';
import { keysToCamel } from '../utils/snakeToCamelCase';

class FtContractService {
  getFtTotalSupply = async (contractId: string): Promise<FtTotalSupplyResponse> => {
    console.log(contractId);
    const totalSupply = await blockchain.masterAccount.viewFunction(
      contractId,
      'ft_total_supply',
      {},
    );
    return { totalSupply: formatNearAmount(totalSupply) };
  };

  getFtBalance = async (accountId: string, contractId: string): Promise<FtBalanceResponse> => {
    const ftBalance = await blockchain.masterAccount.viewFunction(contractId, 'ft_balance_of', {
      account_id: accountId,
    });
    return { balance: formatNearAmount(ftBalance) };
  };

  getFtMeta = async (contractId: string): Promise<FtMetadata> => {
    const ftMeta = await blockchain.masterAccount.viewFunction(contractId, 'ft_metadata', {});
    return keysToCamel(ftMeta);
  };
}

export const ftContractService = new FtContractService();
