import express from 'express';
import { getNFTSupply, getNFTTokens, getToken } from '../controllers/nft.controller';

const router = express.Router();

router.post('/get', getToken);
router.post('/get-many', getNFTTokens);
router.post('/supply', getNFTSupply);

// contract account
//router.post('/mint', mintNFT);
//router.post('/transfer', transferToken);

export default router;
