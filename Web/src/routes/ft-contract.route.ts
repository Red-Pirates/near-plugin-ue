import express from 'express';
import { getFtBalance, getFtMeta, getFtTotalSupply } from '../controllers/ft-contract.controller';

const router = express.Router();

router.get('/:contractId/accounts/:accountId/balance', getFtBalance);
router.get('/:contractId/meta', getFtMeta);
router.get('/:contractId/total-supply', getFtTotalSupply);

export default router;
