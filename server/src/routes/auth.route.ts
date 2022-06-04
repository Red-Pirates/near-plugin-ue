import { createLoginWalletUrl, createTransactionSignUrl } from '../utils/blockchain';
import express from 'express';

const router = express.Router();

router.post('/login-url', async (request, response) => {
  const url = await createLoginWalletUrl(request.body.contractId);
  response.json(url);
});

router.post('/transaction-url', async (request, response) => {
  const url = await createTransactionSignUrl(
    request.body.accountId,
    request.body.receiverId,
    request.body.deposit,
    request.body.method,
    request.body.gas,
    request.body.params,
  );
  response.json(url);
});

router.get('/login-success', async (request, response) => {
  response.sendStatus(200);
});

router.get('/login-failed', async (request, response) => {
  response.sendStatus(200);
});

export default router;
