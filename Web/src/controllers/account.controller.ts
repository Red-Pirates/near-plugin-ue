import { NextFunction, Request, Response } from 'express';
import { userAccountService } from '../service/account.service';

interface GetAccountBalanceParams {
  accountId: string;
}

interface CreateAccountBody {
  name: string;
  amount?: string;
}

export interface GetFTAccountBalanceParams {
  contractId: string;
  accountId: string;
}

export interface GetOwnerNFTTokensParams {
  accountId: string;
  contractId: string;
}

export interface GetOwnerNFTTokensQuery {
  fromIndex: string;
  limit: number;
}

export interface GetOwnerNFTTokensSupplyParams {
  accountId: string;
  contractId: string;
}

export const getAccountBalance = (
  req: Request<GetAccountBalanceParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getAccountBalance(req.params.accountId)
    .then((balance) => res.json(balance))
    .catch(next);
};

export const createAccount = (
  req: Request<never, never, CreateAccountBody>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .createAccount(req.body.name, req.body.amount)
    .then((result) => res.json(result))
    .catch(next);
};

export const getNFTTokens = (
  req: Request<GetOwnerNFTTokensParams, never, never, GetOwnerNFTTokensQuery>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getNFTTokens(req.params.accountId, req.params.contractId, req.query.fromIndex, req.query.limit)
    .then((jsonTokens) => res.json(jsonTokens))
    .catch(next);
};

export const getNFTSupply = (
  req: Request<GetOwnerNFTTokensSupplyParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getNFTSupply(req.params.accountId, req.params.contractId)
    .then((supply) => res.json(supply))
    .catch(next);
};

export const getFTAccountBalance = (
  req: Request<GetFTAccountBalanceParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getFTBalance(req.params.accountId, req.params.contractId)
    .then((balance) => res.json(balance))
    .catch(next);
};
