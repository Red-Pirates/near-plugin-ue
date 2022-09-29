import { NextFunction, Request, Response } from 'express';
import { ftContractService } from '../service/ft-contract.service';

interface FtContractParams {
  contractId: string;
}

export interface FtAccountBalanceParams extends FtContractParams {
  accountId: string;
}

export const getFtBalance = (
  req: Request<FtAccountBalanceParams>,
  res: Response,
  next: NextFunction,
): void => {
  ftContractService
    .getFtBalance(req.params.accountId, req.params.contractId)
    .then((balance) => res.json(balance))
    .catch(next);
};

export const getFtMeta = (
  req: Request<FtContractParams>,
  res: Response,
  next: NextFunction,
): void => {
  ftContractService
    .getFtMeta(req.params.contractId)
    .then((ftMeta) => res.json(ftMeta))
    .catch(next);
};

export const getFtTotalSupply = (
  req: Request<FtContractParams>,
  res: Response,
  next: NextFunction,
): void => {
  ftContractService
    .getFtTotalSupply(req.params.contractId)
    .then((result) => res.json(result))
    .catch(next);
};
