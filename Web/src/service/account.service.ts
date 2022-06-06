import * as blockchain from '../utils/blockchain';
import { formatNearAmount } from 'near-api-js/lib/utils/format';

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
}

export const userAccountService = new UserAccountService();
