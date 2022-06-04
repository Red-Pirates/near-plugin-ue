import { NextFunction, Request, Response } from 'express';
import { userAccountService } from '../service/account.service';

interface Params {
  id: string;
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
