import express from 'express';
import { getAccountBalance } from '../controllers/account.controller';

const router = express.Router();

router.get('/:id/balance', getAccountBalance);

export default router;
