import { InMemoryKeyStore } from 'near-api-js/lib/key_stores';
import config from '../config';
import { Account, KeyPair, Near } from 'near-api-js';

export const keyStore = new InMemoryKeyStore();
keyStore.setKey(config.NETWORK_ID, config.CONTRACT_NAME, KeyPair.fromString(config.PRIVATE_KEY));

const nearConfig = {
  networkId: config.NETWORK_ID,
  nodeUrl: `https://rpc.${config.NETWORK_ID}.near.org`,
  deps: { keyStore },
  headers: {},
};

export const near = new Near(nearConfig);
export const masterAccount = new Account(near.connection, config.CONTRACT_NAME);
