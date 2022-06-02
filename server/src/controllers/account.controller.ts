import { NextFunction, Request, Response } from 'express';
import { userAccountService } from '../service/account.service';

interface Params {
  id: string;
  privateKey: string;
  beneficiaryId: string;
}

interface CreateAccountBody {
  name: string;
}

export const getAccountBalance = (
  req: Request<Params>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getAccountBalance(req.params.id)
    .then((balance) => res.json(balance))
    .catch(next);
};

export const getAccountState = (req: Request<Params>, res: Response, next: NextFunction): void => {
  userAccountService
    .getAccountState(req.params.id)
    .then((state) => res.json(state))
    .catch(next);
};

export const getAccountDetails = (
  req: Request<Params>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .getAccountDetails(req.params.id)
    .then((details) => res.json(details))
    .catch(next);
};

export const createAccount = (
  req: Request<never, never, CreateAccountBody>,
  res: Response,
  next: NextFunction,
): void => {
  userAccountService
    .createAccount(req.body.name)
    .then((account) => res.json(account))
    .catch(next);
};

export const deleteAccount = (req: Request<Params>, res: Response, next: NextFunction): void => {
  userAccountService
    .deleteAccount(req.body.accountId, req.body.privateKey, req.body.beneficiaryId)
    .then(() => res.json())
    .catch(next);
};
