import { Account, KeyPair, Near } from 'near-api-js';
import { InMemoryKeyStore } from 'near-api-js/lib/key_stores';
import config from '../src/config';
import * as fs from 'fs';

const keyStore = new InMemoryKeyStore();
keyStore.setKey(config.NETWORK_ID, config.CONTRACT_NAME, KeyPair.fromString(config.PRIVATE_KEY));

const nearConfig = {
  networkId: config.NETWORK_ID,
  nodeUrl: `https://rpc.${config.NETWORK_ID}.near.org`,
  deps: { keyStore },
  headers: {},
};

const near = new Near(nearConfig);

export const generateRandomString = () => {
  return (Math.random() + 1).toString(36).substring(2);
};

export const createAccount = async (accountId: string) => {
  const masterAccount = new Account(near.connection, config.CONTRACT_NAME);
  const newKeyPair = KeyPair.fromRandom('ed25519');
  await masterAccount.createAccount(
    accountId,
    newKeyPair.getPublicKey(),
    '5000000000000000000000000',
  );
  await keyStore.setKey(config.NETWORK_ID, accountId, newKeyPair);
  return new Account(near.connection, accountId);
};

export const deployContract = async (account: Account, contractFileName: string) => {
  const path = `contracts/${contractFileName}`;
  if (!fs.existsSync(path)) new Error('Contract not found');
  const data = [...fs.readFileSync(path)];
  await account.deployContract(new Uint8Array(data));
  switch (contractFileName) {
    case 'fungible_token.wasm':
      await account.functionCall({
        contractId: account.accountId,
        methodName: 'new_default_meta',
        args: {
          owner_id: account.accountId,
          total_supply: '1000000000000000000000000000000000',
        },
        gas: '100000000000000',
        attachedDeposit: '0',
      });
      break;
    case 'non_fungible_token.wasm':
      await account.functionCall({
        contractId: account.accountId,
        methodName: 'new_default_meta',
        args: {
          owner_id: account.accountId,
        },
        gas: '100000000000000',
        attachedDeposit: '0',
      });
      break;
  }
};
