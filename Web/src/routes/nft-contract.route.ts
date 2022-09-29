import express from 'express';
import {
  getNftMetadata,
  getNFTSupply,
  getNftToken,
  getNftTokens,
  getNftTokensForOwner,
  getNftTotalSupply,
} from '../controllers/nft-contract.controller';

const router = express.Router();

router.get('/:contractId/total-supply', getNftTotalSupply);
router.get('/:contractId/list', getNftTokens);
router.get('/:contractId/metadata', getNftMetadata);
router.get('/:contractId/tokens/:tokenId', getNftToken);

router.get('/:contractId/accounts/:accountId/list', getNftTokensForOwner);
router.get('/:contractId/accounts/:accountId/supply', getNFTSupply);

export default router;
