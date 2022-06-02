import express from 'express';
import { getFTBalance, getFTContractBalance } from '../controllers/ft.controller';

const router = express.Router();

router.post('/balance', getFTBalance);
router.post('/total-balance', getFTContractBalance);

export default router;
