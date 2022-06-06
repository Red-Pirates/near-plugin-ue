import { NextFunction, Request, Response } from 'express';
import { FTService } from '../service/ft.service';
import { GetFTAccountBalanceRequest, GetFTTotalBalanceRequest } from '../models/FT';

export const getFTAccountBalance = (
  req: Request<never, never, GetFTAccountBalanceRequest>,
  res: Response,
  next: NextFunction,
): void => {
  FTService.getFTBalance(req.body.accountId, req.body.contractId)
    .then((balance) => res.json(balance))
    .catch(next);
};

export const getFTContractBalance = (
  req: Request<never, never, GetFTTotalBalanceRequest>,
  res: Response,
  next: NextFunction,
): void => {
  FTService.getFTTotalBalance(req.body.contractId)
    .then((totalBalance) => res.json(totalBalance))
    .catch(next);
};
