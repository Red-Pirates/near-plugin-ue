import { KeyPair, providers, transactions, utils } from 'near-api-js';
import { masterAccount } from '../utils/blockchain';
import config from '../config';
import fs from 'fs';

class ContractService {
  deployContract = async (contractFileName: string) => {
    const path = `contracts/${contractFileName}`;
    if (!fs.existsSync(path)) new Error('Contract not found');
    const data = [...fs.readFileSync(path)];
    await masterAccount.deployContract(new Uint8Array(data));
  };

  callCallContractFunction = async (
    contractId: string,
    method: string,
    params: Record<string, any>,
    attachedGas?: string,
    attachedTokens?: string,
  ) => {
    return await masterAccount.functionCall({
      contractId: contractId,
      methodName: method,
      args: params,
      gas: attachedGas || '25000000000000',
      attachedDeposit: attachedTokens,
    });
  };

  callViewContractFunction = async (
    contractId: string,
    method: string,
    params: Record<string, any>,
  ): Promise<any> => {
    return await masterAccount.viewFunction(contractId, method, params);
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

    return { transactionUrl: newUrl.href };
  };

  createLoginWalletUrl = async (contractId: string) => {
    const newUrl = new URL(`https://wallet.${config.NETWORK_ID}.near.org` + '/login/');
    const accessKey = KeyPair.fromRandom('ed25519');

    newUrl.searchParams.set('success_url', 'http://localhost:3000/api/v1/login/success');
    newUrl.searchParams.set('failure_url', 'http://localhost:3000/api/v1/login/failure');
    newUrl.searchParams.set('contract_id', contractId);
    newUrl.searchParams.set('public_key', accessKey.getPublicKey().toString());

    return { loginUrl: newUrl.toString() };
  };
}

export const contractService = new ContractService();
