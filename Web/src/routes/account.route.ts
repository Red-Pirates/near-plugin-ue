import express from 'express';
import {
  createAccount,
  getAccountBalance,
  getFTAccountBalance,
  getNFTSupply,
  getNFTTokens,
} from '../controllers/account.controller';

const router = express.Router();

router.post('/', createAccount);
router.get('/:accountId/balance', getAccountBalance);
router.get('/:accountId/contracts/:contractId/ft-balance', getFTAccountBalance);
router.get('/:accountId/contracts/:contractId/nft-list', getNFTTokens);
router.get('/:accountId/contracts/:contractId/nft-supply', getNFTSupply);

export default router;
