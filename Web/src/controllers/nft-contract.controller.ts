import { NextFunction, Request, Response } from 'express';
import { nftService } from '../service/nft-contract.service';

interface ContractParams {
  contractId: string;
}

export const getNftTotalSupply = (
  req: Request<ContractParams>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNftTotalSupply(req.params.contractId)
    .then((totalSupply) => res.json(totalSupply))
    .catch(next);
};

interface NftTokensParams extends ContractParams {
  accountId: string;
}

interface NftTokensQuery {
  fromIndex: string;
  limit: number;
}

export const getNftTokens = (
  req: Request<NftTokensParams, never, never, NftTokensQuery>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNftTokens(req.params.contractId, req.query.fromIndex, req.query.limit)
    .then((jsonTokens) => res.json(jsonTokens))
    .catch(next);
};

export const getNftMetadata = (
  req: Request<ContractParams>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNftMetadata(req.params.contractId)
    .then((nftMetadata) => res.json(nftMetadata))
    .catch(next);
};

interface NftTokenParams extends ContractParams {
  tokenId: string;
}

export const getNftToken = (
  req: Request<NftTokenParams>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNftToken(req.params.contractId, req.params.tokenId)
    .then((token) => res.json(token))
    .catch(next);
};

export const getNftTokensForOwner = (
  req: Request<NftTokensParams, never, never, NftTokensQuery>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNftTokensForOwner(
      req.params.accountId,
      req.params.contractId,
      req.query.fromIndex,
      req.query.limit,
    )
    .then((jsonTokens) => res.json(jsonTokens))
    .catch(next);
};

export const getNFTSupply = (
  req: Request<NftTokensParams>,
  res: Response,
  next: NextFunction,
): void => {
  nftService
    .getNftSupplyForOwner(req.params.accountId, req.params.contractId)
    .then((supply) => res.json(supply))
    .catch(next);
};
