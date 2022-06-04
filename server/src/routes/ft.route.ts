import express from 'express';
import { getFTAccountBalance, getFTContractBalance } from '../controllers/ft.controller';

const router = express.Router();

router.post('/balance', getFTAccountBalance);
router.post('/total-balance', getFTContractBalance);

export default router;
