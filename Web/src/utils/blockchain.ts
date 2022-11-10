import { InMemoryKeyStore } from 'near-api-js/lib/key_stores';
import config from '../config';
import { Account, connect, KeyPair, keyStores, Near } from 'near-api-js';

export const keyStore = new InMemoryKeyStore();
keyStore.setKey(config.NETWORK_ID, config.CONTRACT_NAME, KeyPair.fromString(config.PRIVATE_KEY));

const nearConfig = {
  networkId: config.NETWORK_ID,
  nodeUrl: `https://rpc.${config.NETWORK_ID}.near.org`,
  deps: { keyStore },
  masterAccount: config.CONTRACT_NAME,
  headers: {},
};

export const near = new Near(nearConfig);
export const masterAccount = new Account(near.connection, config.CONTRACT_NAME);

export const getAccountByKey = async (accountId: string, secretKey: string) => {
  const keyPair = KeyPair.fromString(secretKey);
  const keyStore = new keyStores.InMemoryKeyStore();
  keyStore.setKey(config.NETWORK_ID, accountId, keyPair);

  const near = await connect({
    networkId: config.NETWORK_ID,
    nodeUrl: `https://rpc.${config.NETWORK_ID}.near.org`,
    deps: { keyStore },
    headers: {},
    masterAccount: accountId,
  });
  return await near.account(accountId);
};
