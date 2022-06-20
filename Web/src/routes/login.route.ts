import express from 'express';
import { loginFailed, loginSuccess } from '../controllers/login.controller';

const router = express.Router();

router.get('/success', loginSuccess);
router.get('/failure', loginFailed);

export default router;
