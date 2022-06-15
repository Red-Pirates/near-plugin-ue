import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, deployContract, generateRandomString } from './test-utils';
import config from '../src/config';
import { parseNearAmount } from 'near-api-js/lib/utils/format';

describe('Account endpoints', () => {
  const request = supertest(app);
  let testAccount: Account;
  let ftAccount: Account;
  let nftAccount: Account;

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
    nftAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('NFT account created.');
    await deployContract(nftAccount, 'non_fungible_token.wasm');
    console.log('NFT contract deployed.');
    await nftAccount.functionCall({
      contractId: nftAccount.accountId,
      methodName: 'nft_mint',
      args: {
        token_id: 'token-1',
        token_metadata: {
          title: 'test',
          description: 'test nft 1',
        },
        receiver_id: testAccount.accountId,
      },
      gas: '200000000000000',
      attachedDeposit: parseNearAmount('0.01'),
    });
    console.log('NFT token-1 minted.');
    await nftAccount.functionCall({
      contractId: nftAccount.accountId,
      methodName: 'nft_mint',
      args: {
        token_id: 'token-2',
        token_metadata: {
          title: 'test',
          description: 'test nft 2',
        },
        receiver_id: testAccount.accountId,
      },
      gas: '200000000000000',
      attachedDeposit: parseNearAmount('0.01'),
    });
    console.log('NFT token-2 minted.');
  });

  afterAll(async () => {
    await testAccount.deleteAccount(config.CONTRACT_NAME);
    await ftAccount.deleteAccount(config.CONTRACT_NAME);
    await nftAccount.deleteAccount(config.CONTRACT_NAME);
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

  it('should get account ft balance', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${ftAccount.accountId}/ft-balance`,
      )
      .then((res) => {
        console.log(res.body);
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('tokenName');
        expect(res.body).toHaveProperty('symbol');
        expect(res.body).toHaveProperty('icon');
        expect(res.body).toHaveProperty('balance');
        expect(res.body.balance).toEqual('100');
      });
  });

  it('should throw an error for an account without ft contract', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${testAccount.accountId}/ft-balance`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });

  it('should throw an error for an account without nft contract', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${testAccount.accountId}/nft-list`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });

  it('should get all account nfts', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${nftAccount.accountId}/nft-list`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.length).toEqual(2);
        expect(res.body).toEqual(
          expect.arrayContaining([
            expect.objectContaining({ tokenId: 'token-1' }),
            expect.objectContaining({ tokenId: 'token-1' }),
            expect.objectContaining({ description: 'test nft 1' }),
            expect.objectContaining({ description: 'test nft 2' }),
          ]),
        );
      });
  });

  it('should get account nfts from index 0 with limit 1', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${nftAccount.accountId}/nft-list?fromIndex=0&limit=1`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.length).toEqual(1);
        expect(res.body).toEqual(
          expect.arrayContaining([
            expect.objectContaining({ tokenId: 'token-1' }),
            expect.objectContaining({ description: 'test nft 1' }),
          ]),
        );
      });
  });

  it('should get account nfts from index 1 with limit 1', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${nftAccount.accountId}/nft-list?fromIndex=1&limit=1`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.length).toEqual(1);
        expect(res.body).toEqual(
          expect.arrayContaining([
            expect.objectContaining({ tokenId: 'token-2' }),
            expect.objectContaining({ description: 'test nft 2' }),
          ]),
        );
      });
  });

  it('should get nft supply for account with nft', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${nftAccount.accountId}/nft-supply`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toEqual('2');
      });
  });

  it('should get nft supply for account without nft', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${nftAccount.accountId}/contracts/${nftAccount.accountId}/nft-supply`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toEqual('0');
      });
  });

  it('should throw an error for an account without nft contract', async () => {
    return request
      .get(
        `${PATH_PREFIX}/accounts/${testAccount.accountId}/contracts/${testAccount.accountId}/nft-supply`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });
});
