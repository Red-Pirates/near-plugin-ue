import * as blockchain from '../utils/blockchain';
import { KeyPair } from 'near-api-js';
import config from '../config';
import { formatNearAmount } from 'near-api-js/lib/utils/format';

class UserAccountService {
  loadAccount = async (accountId: string) => {
    return await blockchain.near.account(accountId);
  };

  getAccountBalance = async (accountId: string) => {
    const account = await this.loadAccount(accountId);
    const balance = await account.getAccountBalance();
    return {
      total: formatNearAmount(balance.total),
      stateStaked: formatNearAmount(balance.stateStaked),
      staked: formatNearAmount(balance.staked),
      available: formatNearAmount(balance.available),
    };
  };

  getAccountState = async (accountId: string) => {
    const account = await this.loadAccount(accountId);
    return await account.state();
  };

  getAccountDetails = async (accountId: string) => {
    const account = await this.loadAccount(accountId);
    return await account.getAccountDetails();
  };

  createAccount = async (name: string) => {
    const keyPair = KeyPair.fromRandom('ed25519');
    const newAccountId = `${name}.${config.CONTRACT_NAME}`;
    await blockchain.masterAccount.createAccount(
      newAccountId, // new account name
      keyPair.getPublicKey().toString(), // public key for new account
      '1000000000000000000000000', // initial balance for new account in yoctoNEAR
    );
  };

  deleteAccount = async (accountId: string, privateKey: string, beneficiaryId: string) => {
    const account = await blockchain.getAccountByKey(accountId, privateKey);
    await account.deleteAccount(beneficiaryId);
  };
}

export const userAccountService = new UserAccountService();
