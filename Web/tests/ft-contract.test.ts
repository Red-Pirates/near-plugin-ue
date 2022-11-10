import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, deployContract, generateRandomString } from './test-utils';
import config from '../src/config';
import { parseNearAmount } from 'near-api-js/lib/utils/format';

describe('Ft endpoints', () => {
  const request = supertest(app);
  let testAccount: Account;
  let ftAccount: Account;

  beforeAll(async () => {
    testAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('Test account created.');
    ftAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('FT account created.');
    await deployContract(ftAccount, 'fungible_token.wasm');
    console.log('FT contract deployed.');
    await testAccount.functionCall({
      contractId: ftAccount.accountId,
      methodName: 'storage_deposit',
      args: {},
      gas: '200000000000000',
      attachedDeposit: parseNearAmount('0.01'),
    });
    await ftAccount.functionCall({
      contractId: ftAccount.accountId,
      methodName: 'ft_transfer',
      args: {
        receiver_id: testAccount.accountId,
        amount: parseNearAmount('100'),
      },
      gas: '200000000000000',
      attachedDeposit: '1',
    });
    console.log('FT transferred to the testAccount.');
  });

  afterAll(async () => {
    await testAccount.deleteAccount(config.CONTRACT_NAME);
    await ftAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should get total ft balance', async () => {
    return request
      .get(`${PATH_PREFIX}/ft-contracts/${ftAccount.accountId}/total-supply`)
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.balance).toEqual('1,000,000,000');
      });
  });

  it('should get ft meta', async () => {
    return request.get(`${PATH_PREFIX}/ft-contracts/${ftAccount.accountId}/meta`).then((res) => {
      expect(res.statusCode).toEqual(200);
      expect(res.body).toHaveProperty('name');
      expect(res.body).toHaveProperty('symbol');
      expect(res.body).toHaveProperty('icon');
      expect(res.body).toHaveProperty('spec');
      expect(res.body).toHaveProperty('reference');
      expect(res.body).toHaveProperty('referenceHash');
      expect(res.body).toHaveProperty('decimals');
    });
  });

  it('should get account ft balance', async () => {
    return request
      .get(
        `${PATH_PREFIX}/ft-contracts/${ftAccount.accountId}/accounts/${testAccount.accountId}/balance`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.balance).toEqual('100');
      });
  });

  it('should throw an error for an account without ft contract', async () => {
    return request
      .get(
        `${PATH_PREFIX}/ft-contracts/${testAccount.accountId}/accounts/${testAccount.accountId}/balance`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });
});
