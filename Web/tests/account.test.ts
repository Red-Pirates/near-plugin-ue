import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, generateRandomString } from './test-utils';
import config from '../src/config';
import { parseNearAmount } from 'near-api-js/lib/utils/format';

describe('Account endpoints', () => {
  const request = supertest(app);
  let testAccount: Account;

  beforeAll(async () => {
    testAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('Test account created.');
  });

  afterAll(async () => {
    await testAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should get account balance', async () => {
    return request.get(`${PATH_PREFIX}/accounts/${testAccount.accountId}/balance`).then((res) => {
      expect(res.statusCode).toEqual(200);
      expect(res.body).toHaveProperty('total');
      expect(res.body).toHaveProperty('stateStaked');
      expect(res.body).toHaveProperty('staked');
      expect(res.body).toHaveProperty('available');
    });
  });

  it('should get account state', async () => {
    return request.get(`${PATH_PREFIX}/accounts/${testAccount.accountId}/state`).then((res) => {
      expect(res.statusCode).toEqual(200);
      expect(res.body).toHaveProperty('amount');
      expect(res.body).toHaveProperty('blockHash');
      expect(res.body).toHaveProperty('blockHeight');
      expect(res.body).toHaveProperty('codeHash');
      expect(res.body).toHaveProperty('locked');
      expect(res.body).toHaveProperty('storagePaidAt');
      expect(res.body).toHaveProperty('storageUsage');
    });
  });

  it('should get account details', async () => {
    return request.get(`${PATH_PREFIX}/accounts/${testAccount.accountId}/details`).then((res) => {
      expect(res.statusCode).toEqual(200);
      expect(res.body).toHaveProperty('authorizedApps');
    });
  });

  it('should get transaction details', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/transactions/FB7YE1ZapLwJW6oWLXN4hzmdftV9dLqBZL1vURdJn7kt`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
      });
  });

  it('should create a new account', async () => {
    const newAccountName = generateRandomString();
    return request
      .post(`${PATH_PREFIX}/accounts/`)
      .send({
        name: newAccountName,
        amount: parseNearAmount('1'),
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('accountId');
        expect(res.body).toHaveProperty('publicKey');
        expect(res.body.accountId).toEqual(`${newAccountName}.${config.CONTRACT_NAME}`);
      });
  });
});
