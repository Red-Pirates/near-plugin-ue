import { NextFunction, Request, Response } from 'express';
import { nftService } from '../service/nft.service';
import {
  GetOwnerNFTTokensRequest,
  GetOwnerNFTTokensSupplyRequest,
  GetTokenRequest,
  NFTResponse,
} from '../models/NFT';

export const getNFTTokens = (
  req: Request<never, never, GetOwnerNFTTokensRequest>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNFTTokens(req.body.accountId, req.body.contractId, req.body.fromIndex, req.body.limit)
    .then((jsonTokens) => res.json(jsonTokens))
    .catch(next);
};

export const getNFTSupply = (
  req: Request<never, never, GetOwnerNFTTokensSupplyRequest>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNFTSupply(req.body.accountId, req.body.contractId)
    .then((supply) => res.json(supply))
    .catch(next);
};

export const getToken = (
  req: Request<never, never, GetTokenRequest>,
  res: Response<NFTResponse>,
  next: NextFunction,
): void => {
  nftService
    .getToken(req.body.tokenId, req.body.contractId)
    .then((jsonToken) => res.json(jsonToken))
    .catch(next);
};
