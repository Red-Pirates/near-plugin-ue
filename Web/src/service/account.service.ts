import * as blockchain from '../utils/blockchain';
import { near } from '../utils/blockchain';
import { formatNearAmount } from 'near-api-js/lib/utils/format';
import { KeyPair } from 'near-api-js';
import config from '../config';
import { keysToCamel } from '../utils/snakeToCamelCase';

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

  getAccountState = async (accountId: string) => {
    const account = await blockchain.near.account(accountId);
    const state = await account.state();
    state.amount = formatNearAmount(state.amount);
    return keysToCamel(state);
  };

  getAccountDetails = async (accountId: string) => {
    const account = await blockchain.near.account(accountId);
    const details = await account.getAccountDetails();
    details.authorizedApps = details.authorizedApps.map((t) => {
      return { ...t, amount: formatNearAmount(t.amount) };
    });
    return details;
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

  geTransactionStatus = async (accountId: string, txHash: string) => {
    const response = await near.connection.provider.txStatus(txHash, accountId);
    return keysToCamel(response);
  };
}

export const userAccountService = new UserAccountService();
