import express from 'express';
import {
  getLoginUrl,
  getTransactionUrl,
  invokeViewFunction,
} from '../controllers/contract.controller';

const router = express.Router();

router.post('/login-url', getLoginUrl);
router.post('/transaction-url', getTransactionUrl);

router.post('/view', invokeViewFunction);

export default router;
