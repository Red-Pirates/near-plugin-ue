import express from 'express';
import {
  createAccount,
  deleteAccount,
  getAccountBalance,
  getAccountDetails,
  getAccountState,
} from '../controllers/account.controller';

const router = express.Router();

//router.post('/', createAccount);
//router.post('/delete', deleteAccount);

router.get('/:id/balance', getAccountBalance);
router.get('/:id/state', getAccountState);
router.get('/:id/details', getAccountDetails);

export default router;
