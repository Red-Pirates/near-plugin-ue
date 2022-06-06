import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, generateRandomString } from './test-utils';
import config from '../src/config';

describe('Account endpoints', () => {
  const request = supertest(app);
  let testAccount: Account;

  beforeAll(async () => {
    testAccount = await createAccount(generateRandomString() + `.${config.CONTRACT_NAME}`);
  });

  afterAll(async () => {
    await testAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should get account balance', async () => {
    return request.get(`${PATH_PREFIX}/account/${testAccount.accountId}/balance`).then((res) => {
      expect(res.statusCode).toEqual(200);
      expect(res.body).toHaveProperty('total');
      expect(res.body).toHaveProperty('stateStaked');
      expect(res.body).toHaveProperty('staked');
      expect(res.body).toHaveProperty('available');
    });
  });
});
