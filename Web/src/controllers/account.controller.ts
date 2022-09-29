import { NextFunction, Request, Response } from 'express';
import { userAccountService } from '../service/account.service';

interface AccountParams {
  accountId: string;
}

export const getAccountBalance = (
  req: Request<AccountParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getAccountBalance(req.params.accountId)
    .then((balance) => res.json(balance))
    .catch(next);
};

export const getAccountState = (
  req: Request<AccountParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getAccountState(req.params.accountId)
    .then((state) => res.json(state))
    .catch(next);
};

export const getAccountDetails = (
  req: Request<AccountParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getAccountDetails(req.params.accountId)
    .then((details) => res.json(details))
    .catch(next);
};

interface CreateAccountBody {
  name: string;
  amount?: string;
}

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

interface TransactionParams extends AccountParams {
  txHash: string;
}

export const getTransactionStatus = (
  req: Request<TransactionParams>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .geTransactionStatus(req.params.accountId, req.params.txHash)
    .then((result) => res.json(result))
    .catch(next);
};
