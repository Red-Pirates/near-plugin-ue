import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, generateRandomString } from './test-utils';
import config from '../src/config';

describe('Contract endpoints', () => {
  const request = supertest(app);
  let testAccount: Account;

  beforeAll(async () => {
    testAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('Test account created.');
  });

  afterAll(async () => {
    await testAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should deploy contract', async () => {
    return request
      .post(`${PATH_PREFIX}/contracts/deploy`)
      .send({ fileName: 'fungible_token.wasm' })
      .then((res) => {
        expect(res.statusCode).toEqual(204);
      });
  });

  it('should create and return login url', async () => {
    return request
      .get(`${PATH_PREFIX}/contracts/${testAccount.accountId}/login-url`)
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('loginUrl');
      });
  });

  it('should create and return transaction url', async () => {
    return request
      .post(`${PATH_PREFIX}/contracts/transaction-url`)
      .send({
        signerId: testAccount.accountId,
        receiverId: config.CONTRACT_NAME,
        method: 'ft_transfer',
        params: {
          receiver_id: config.CONTRACT_NAME,
          amount: '1000000000000000000000000',
          memo: 'test',
        },
        gas: '100000000000000',
        deposit: '1',
        callbackUrl: 'http://localhost:3000/',
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('transactionUrl');
      });
  });

  it('should invoke call contract function', async () => {
    return request
      .post(`${PATH_PREFIX}/contracts/call`)
      .send({
        contractId: 'museum.testnet',
        method: 'add_myself_as_contributor',
        params: {},
        attachedGas: '300000000000000',
        attachedTokens: '1',
      })
      .then((res) => {
        console.log(res.body);
        expect(res.statusCode).toEqual(200);
      });
  });

  it('should invoke view contract function', async () => {
    return request
      .post(`${PATH_PREFIX}/contracts/view`)
      .send({
        contractId: 'museum.testnet',
        method: 'get_meme_list',
        params: {},
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
      });
  });
});
