import { NextFunction, Request, Response } from 'express';
import { nftService } from '../service/nft.service';
import { NearNFTMetadata, NFTResponse } from '../models/NFT';

interface MintNFTBody {
  receiverId: string;
  tokenMetadata: NearNFTMetadata;
  tokenId: string;
}

interface TransferTokenBody {
  receiverId: string;
  tokenId: string;
  memo: string;
}

interface GetTokenBody {
  tokenId: string;
  contractId?: string;
}

interface GetOwnerNFTTokens {
  accountId: string;
  contractId: string;
  fromIndex: string;
  limit: number;
}

interface GetOwnerNFTTokensSupply {
  accountId: string;
  contractId: string;
}

export const mintNFT = (
  req: Request<never, never, MintNFTBody>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .mintNFT(req.body.tokenMetadata, req.body.receiverId, req.body.tokenId)
    .then((state) => res.json(state))
    .catch(next);
};

export const transferToken = (
  req: Request<never, never, TransferTokenBody>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .transferToken(req.body.receiverId, req.body.tokenId, req.body.memo)
    .then(() => res.json())
    .catch(next);
};

export const getNFTTokens = (
  req: Request<never, never, GetOwnerNFTTokens>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNFTTokens(req.body.accountId, req.body.contractId, req.body.fromIndex, req.body.limit)
    .then((jsonTokens) => res.json(jsonTokens))
    .catch(next);
};

export const getNFTSupply = (
  req: Request<never, never, GetOwnerNFTTokensSupply>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNFTSupply(req.body.accountId, req.body.contractId)
    .then((supply) => res.json(supply))
    .catch(next);
};

export const getToken = (
  req: Request<never, never, GetTokenBody>,
  res: Response<NFTResponse>,
  next: NextFunction,
): void => {
  nftService
    .getToken(req.body.tokenId, req.body.contractId)
    .then((jsonToken) => res.json(jsonToken))
    .catch(next);
};
