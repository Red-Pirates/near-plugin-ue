import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, deployContract, generateRandomString } from './test-utils';
import config from '../src/config';
import { parseNearAmount } from 'near-api-js/lib/utils/format';

describe('Nft endpoints', () => {
  const request = supertest(app);
  let testAccount: Account;
  let nftAccount: Account;

  const token1Info = {
    tokenId: 'token-1',
    title: 'test 1',
    description: 'test nft 1',
    media:
      'https://bafkreifx5sqsir6m2elstlnxqq4xua75ua3d3c6j5htfzern2x6g4qpxjm.ipfs.nftstorage.link/',
  };
  const token2Info = {
    tokenId: 'token-2',
    title: 'test 2',
    description: 'test nft 2',
    media:
      'https://bafkreifx5sqsir6m2elstlnxqq4xua75ua3d3c6j5htfzern2x6g4qpxjm.ipfs.nftstorage.link/',
  };

  beforeAll(async () => {
    testAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('Test account created.');
    nftAccount = await createAccount(`${generateRandomString()}.${config.CONTRACT_NAME}`);
    console.log('NFT account created.');
    await deployContract(nftAccount, 'non_fungible_token.wasm');
    console.log('NFT contract deployed.');
    await nftAccount.functionCall({
      contractId: nftAccount.accountId,
      methodName: 'nft_mint',
      args: {
        token_id: token1Info.tokenId,
        token_metadata: {
          title: token1Info.title,
          description: token1Info.description,
          media: token1Info.media,
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
        token_id: token2Info.tokenId,
        token_metadata: {
          title: token2Info.title,
          description: token2Info.description,
          media: token2Info.media,
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
    await nftAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should throw an error for an account without nft contract when getting total supply', async () => {
    return request
      .get(`${PATH_PREFIX}/nft-contracts/${testAccount.accountId}/total-supply`)
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });

  it('should get total nft supply', async () => {
    return request
      .get(`${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/total-supply`)
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.nftSupply).toEqual('2');
      });
  });

  it('should get nft metadata', async () => {
    return request
      .get(`${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/metadata`)
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('spec');
        expect(res.body).toHaveProperty('name');
        expect(res.body).toHaveProperty('symbol');
        expect(res.body).toHaveProperty('icon');
        expect(res.body).toHaveProperty('baseUri');
        expect(res.body).toHaveProperty('reference');
        expect(res.body).toHaveProperty('referenceHash');
      });
  });

  it('should throw an error when getting a non-existent token', async () => {
    return request
      .get(`${PATH_PREFIX}/nft-contracts/${testAccount.accountId}/tokens/token-x`)
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });

  it('should get existent token', async () => {
    return request
      .get(`${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/tokens/${token1Info.tokenId}`)
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.tokenId).toEqual(token1Info.tokenId);
        expect(res.body.ownerId).toEqual(testAccount.accountId);
        expect(res.body.metadata.title).toEqual(token1Info.title);
        expect(res.body.metadata.description).toEqual(token1Info.description);
        expect(res.body.metadata.media).toEqual(token1Info.media);
      });
  });

  it('should throw an error for an account without nft contract when getting nfts', async () => {
    return request.get(`${PATH_PREFIX}/nft-contracts/${testAccount.accountId}/list`).then((res) => {
      expect(res.statusCode).toEqual(500);
      expect(res.body).toHaveProperty('error');
    });
  });

  it('should get all nft tokens in contract', async () => {
    return request.get(`${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/list`).then((res) => {
      expect(res.statusCode).toEqual(200);
      expect(res.body.nftTokens.length).toEqual(2);
      expect(res.body.nftTokens).toEqual(
        expect.arrayContaining([
          expect.objectContaining({ tokenId: token1Info.tokenId }),
          expect.objectContaining({ ownerId: testAccount.accountId }),
          expect.objectContaining({ tokenId: token2Info.tokenId }),
          expect.objectContaining({
            metadata: expect.objectContaining({ description: token1Info.description }),
          }),
          expect.objectContaining({
            metadata: expect.objectContaining({ description: token2Info.description }),
          }),
        ]),
      );
    });
  });

  it('should throw an error for an account without nft contract', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${testAccount.accountId}/accounts/${testAccount.accountId}/list`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });

  it('should get all account nfts', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/accounts/${testAccount.accountId}/list`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.accountNftTokens.length).toEqual(2);
        console.log(res.body);
        expect(res.body.accountNftTokens).toEqual(
          expect.arrayContaining([
            expect.objectContaining({ tokenId: token1Info.tokenId }),
            expect.objectContaining({ ownerId: testAccount.accountId }),
            expect.objectContaining({ tokenId: token2Info.tokenId }),
            expect.objectContaining({
              metadata: expect.objectContaining({ description: token1Info.description }),
            }),
            expect.objectContaining({
              metadata: expect.objectContaining({ description: token2Info.description }),
            }),
          ]),
        );
      });
  });

  it('should get account nfts from index 0 with limit 1', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/accounts/${testAccount.accountId}/list?fromIndex=0&limit=1`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.accountNftTokens.length).toEqual(1);
        expect(res.body.accountNftTokens).toEqual(
          expect.arrayContaining([
            expect.objectContaining({ tokenId: token1Info.tokenId }),
            expect.objectContaining({ ownerId: testAccount.accountId }),
            expect.objectContaining({
              metadata: expect.objectContaining({ description: token1Info.description }),
            }),
          ]),
        );
      });
  });

  it('should get account nfts from index 1 with limit 1', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/accounts/${testAccount.accountId}/list?fromIndex=1&limit=1`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.accountNftTokens.length).toEqual(1);
        expect(res.body.accountNftTokens).toEqual(
          expect.arrayContaining([
            expect.objectContaining({ tokenId: token2Info.tokenId }),
            expect.objectContaining({ ownerId: testAccount.accountId }),
            expect.objectContaining({
              metadata: expect.objectContaining({ description: token2Info.description }),
            }),
          ]),
        );
      });
  });

  it('should get nft supply for account with nft', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/accounts/${testAccount.accountId}/supply`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.nftSupply).toEqual('2');
      });
  });

  it('should get nft supply for account without nft', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${nftAccount.accountId}/accounts/${nftAccount.accountId}/supply`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body.nftSupply).toEqual('0');
      });
  });

  it('should throw an error for an account without nft contract', async () => {
    return request
      .get(
        `${PATH_PREFIX}/nft-contracts/${testAccount.accountId}/accounts/${testAccount.accountId}/supply`,
      )
      .then((res) => {
        expect(res.statusCode).toEqual(500);
        expect(res.body).toHaveProperty('error');
      });
  });
});
