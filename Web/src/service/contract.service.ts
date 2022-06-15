import { Account, KeyPair, providers, transactions, utils } from 'near-api-js';
import { near } from '../utils/blockchain';
import config from '../config';

class ContractService {
  invokeViewFunction = async (
    contractId: string,
    method: string,
    params: Record<string, any>,
  ): Promise<any> => {
    const account = new Account(near.connection, contractId);
    return await account.viewFunction(contractId, method, params);
  };

  createTransactionSignUrl = async (
    signerId: string,
    receiverId: string,
    method: string,
    params: Record<string, any>,
    gas: string,
    deposit: string,
    callbackUrl: string,
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
        signerId,
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

    newUrl.searchParams.set('callbackUrl', callbackUrl);

    return newUrl.href;
  };

  createLoginWalletUrl = async (
    contractId: string,
    successUrl: string,
    failureUrl: string,
    methodNames?: string[],
  ) => {
    const newUrl = new URL(`https://wallet.${config.NETWORK_ID}.near.org` + '/login/');
    const accessKey = KeyPair.fromRandom('ed25519');

    newUrl.searchParams.set('success_url', successUrl);
    newUrl.searchParams.set('failure_url', failureUrl);
    newUrl.searchParams.set('contract_id', contractId);
    newUrl.searchParams.set('public_key', accessKey.getPublicKey().toString());

    if (methodNames) {
      methodNames.forEach((methodName) => {
        newUrl.searchParams.append('methodNames', methodName);
      });
    }
    return newUrl.toString();
  };
}

export const contractService = new ContractService();
