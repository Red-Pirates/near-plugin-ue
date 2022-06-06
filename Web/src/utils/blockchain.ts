import { InMemoryKeyStore } from 'near-api-js/lib/key_stores';
import config from '../config';
import {
  Account,
  connect,
  KeyPair,
  keyStores,
  Near,
  transactions,
  utils,
  providers,
} from 'near-api-js';
import { FinalExecutionOutcome } from 'near-api-js/lib/providers';

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

export const getAccountByKey = async function (
  accountId: string,
  privateKey: string,
  headers?: any,
) {
  const keyStore = new keyStores.InMemoryKeyStore();
  keyStore.setKey(config.NETWORK_ID, accountId, KeyPair.fromString(privateKey));

  const near = await connect({
    networkId: config.NETWORK_ID,
    deps: { keyStore },
    masterAccount: accountId,
    nodeUrl: `https://rpc.${config.NETWORK_ID}.near.org`,
    headers: headers || {},
  });

  return await near.account(accountId);
};

export const callContractFunction = async (
  account: Account,
  method: string,
  params: Record<string, any>,
  attachedGas?: string,
  attachedTokens?: string,
): Promise<FinalExecutionOutcome> => {
  return await account.functionCall({
    contractId: config.CONTRACT_NAME,
    methodName: method,
    args: params,
    gas: attachedGas,
    attachedDeposit: attachedTokens,
  });
};

export const viewContractFunction = async (
  account: Account,
  contractId: string,
  method: string,
  params: Record<string, any>,
): Promise<any> => {
  return await account.viewFunction(contractId, method, params);
};
export const createTransactionSignUrl = async (
  accountId: string,
  receiverId: string,
  deposit: string,
  method: string,
  gas: string,
  params: Record<string, any>,
) => {
  const provider = new providers.JsonRpcProvider({
    url: `https://rpc.${config.NETWORK_ID}.near.org`,
  });

  const actions = [
    method === '!transfer'
      ? transactions.transfer(deposit)
      : transactions.functionCall(method, Buffer.from(JSON.stringify(params)), gas, deposit),
  ];
  const block = await provider.block({ finality: 'final' });
  const keypair = KeyPair.fromRandom('ed25519');
  const txs = [
    transactions.createTransaction(
      accountId,
      keypair.getPublicKey(),
      receiverId,
      1,
      actions,
      utils.serialize.base_decode(block.header.hash),
    ),
  ];
  const newUrl = new URL('sign', `https://wallet.${config.NETWORK_ID}.near.org/`);
  newUrl.searchParams.set(
    'transactions',
    txs
      .map((transaction) => utils.serialize.serialize(transactions.SCHEMA, transaction))
      .map((serialized) => Buffer.from(serialized).toString('base64'))
      .join(','),
  );
  newUrl.searchParams.set('callbackUrl', 'http://localhost:3000/api/v1/auth/login_success');

  return newUrl.href;
};

export const createLoginWalletUrl = async (contractId: string, methodNames?: string[]) => {
  const newUrl = new URL(`https://wallet.${config.NETWORK_ID}.near.org` + '/login/');
  const accessKey = KeyPair.fromRandom('ed25519');

  newUrl.searchParams.set('success_url', 'http://localhost:3000/api/v1/auth/login_success');
  newUrl.searchParams.set('failure_url', 'http://localhost:3000/api/v1/auth/login_failed');
  newUrl.searchParams.set('contract_id', contractId);
  newUrl.searchParams.set('public_key', accessKey.getPublicKey().toString());

  if (methodNames) {
    methodNames.forEach((methodName) => {
      newUrl.searchParams.append('methodNames', methodName);
    });
  }
  return { loginUrl: newUrl.toString() };
};
