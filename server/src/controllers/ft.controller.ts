import { NextFunction, Request, Response } from 'express';
import { FTService } from '../service/ft.service';

interface GetFTBalanceBody {
  contractId: string;
  accountId: string;
}

interface GetFTTotalBalanceBody {
  contractId: string;
}

export const getFTBalance = (
  req: Request<never, never, GetFTBalanceBody>,
  res: Response,
  next: NextFunction,
): void => {
  FTService.getFTBalance(req.body.accountId, req.body.contractId)
    .then((balance) => res.json(balance))
    .catch(next);
};

export const getFTContractBalance = (
  req: Request<never, never, GetFTTotalBalanceBody>,
  res: Response,
  next: NextFunction,
): void => {
  FTService.getFTTotalBalance(req.body.contractId)
    .then((totalBalance) => res.json(totalBalance))
    .catch(next);
};
