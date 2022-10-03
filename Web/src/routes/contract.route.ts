import express from 'express';
import {
  callContractFunction,
  deployContract,
  getLoginUrl,
  getTransactionUrl,
  invokeViewFunction,
} from '../controllers/contract.controller';

const router = express.Router();

router.get('/:contractId/login-url', getLoginUrl);

router.post('/deploy', deployContract);
router.post('/transaction-url', getTransactionUrl);
router.post('/view', invokeViewFunction);
router.post('/call', callContractFunction);

export default router;
