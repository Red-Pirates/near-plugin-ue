import supertest from 'supertest';
import app, { PATH_PREFIX } from '../src/app';
import { Account } from 'near-api-js';
import { createAccount, deployContract, generateRandomString } from './test-utils';
import config from '../src/config';
import { parseNearAmount } from 'near-api-js/lib/utils/format';

describe('Non Fungible Token endpoints', () => {
  const request = supertest(app);
  let nftContractAccount: Account;

  beforeAll(async () => {
    nftContractAccount = await createAccount(generateRandomString() + `.${config.CONTRACT_NAME}`);
    await deployContract(nftContractAccount, 'non_fungible_token.wasm');

    await nftContractAccount.functionCall({
      contractId: nftContractAccount.accountId,
      methodName: 'nft_mint',
      args: {
        token_id: 'token-1',
        token_metadata: {
          title: 'test',
          description: 'test nft 1',
        },
        receiver_id: nftContractAccount.accountId,
      },
      gas: '200000000000000',
      attachedDeposit: parseNearAmount('0.01'),
    });

    await nftContractAccount.functionCall({
      contractId: nftContractAccount.accountId,
      methodName: 'nft_mint',
      args: {
        token_id: 'token-2',
        token_metadata: {
          title: 'test',
          description: 'test nft 2',
        },
        receiver_id: nftContractAccount.accountId,
      },
      gas: '200000000000000',
      attachedDeposit: parseNearAmount('0.01'),
    });
  });

  afterAll(async () => {
    await nftContractAccount.deleteAccount(config.CONTRACT_NAME);
  });

  it('should get nft', async () => {
    return request
      .post(`${PATH_PREFIX}/nft/get`)
      .send({
        tokenId: 'token-1',
        contractId: nftContractAccount.accountId,
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
        expect(res.body).toHaveProperty('title');
        expect(res.body).toHaveProperty('description');
        expect(res.body).toHaveProperty('media');
        expect(res.body).toHaveProperty('copies');
      });
  });

  it('should get all account nfts', async () => {
    return request
      .post(`${PATH_PREFIX}/nft/get-many`)
      .send({
        contractId: nftContractAccount.accountId,
        accountId: nftContractAccount.accountId,
      })
      .then((res) => {
        expect(res.statusCode).toEqual(200);
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
});
