import express from 'express';
import {
  createAccount,
  getAccountBalance,
  getAccountDetails,
  getAccountState,
  getTransactionStatus,
} from '../controllers/account.controller';

const router = express.Router();

router.post('/', createAccount);

router.get('/:accountId/balance', getAccountBalance);
router.get('/:accountId/state', getAccountState);
router.get('/:accountId/details', getAccountDetails);
router.get('/:accountId/transactions/:txHash', getTransactionStatus);

export default router;
