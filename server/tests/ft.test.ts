import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, deployContract, generateRandomString } from './test-utils';
import config from '../src/config';

describe('Fungible token endpoints', () => {
  const request = supertest(app);
  let ftContractAccount: Account;

  beforeAll(async () => {
    ftContractAccount = await createAccount(generateRandomString() + `.${config.CONTRACT_NAME}`);
    await deployContract(ftContractAccount, 'fungible_token.wasm');
  });

  afterAll(async () => {
    await ftContractAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should get account ft balance', async () => {
    return request
      .post(`${PATH_PREFIX}/ft/balance`)
      .send({
        accountId: ftContractAccount.accountId,
        contractId: ftContractAccount.accountId,
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('tokenName');
        expect(res.body).toHaveProperty('symbol');
        expect(res.body).toHaveProperty('icon');
        expect(res.body).toHaveProperty('balance');
      });
  });

  it('should get total ft balance', async () => {
    return request
      .post(`${PATH_PREFIX}/ft/total-balance`)
      .send({
        contractId: ftContractAccount.accountId,
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('tokenName');
        expect(res.body).toHaveProperty('symbol');
        expect(res.body).toHaveProperty('icon');
        expect(res.body).toHaveProperty('balance');
      });
  });
});
