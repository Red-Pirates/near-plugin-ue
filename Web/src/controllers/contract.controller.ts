import { NextFunction, Request, Response } from 'express';
import { contractService } from '../service/contract.service';
import { loginService } from '../service/login.service';

interface InvokeViewFunctionBody {
  contractId: string;
  method: string;
  params: Record<string, any>;
}

interface GetTransactionSignInUrlBody {
  signerId: string;
  receiverId: string;
  method: string;
  params: Record<string, any>;
  gas: string;
  deposit: string;
  callbackUrl: string;
}

interface GetLoginUrlParams {
  contractId: string;
}

export const invokeViewFunction = (
  req: Request<never, never, InvokeViewFunctionBody>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .invokeViewFunction(req.body.contractId, req.body.method, req.body.params)
    .then((result) => res.json(result))
    .catch(next);
};

export const getLoginUrl = (
  req: Request<GetLoginUrlParams>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .createLoginWalletUrl(req.params.contractId)
    .then((result) => res.json(result))
    .catch(next);
};

export const getTransactionUrl = (
  req: Request<never, never, GetTransactionSignInUrlBody>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .createTransactionSignUrl(
      req.body.signerId,
      req.body.receiverId,
      req.body.method,
      req.body.params,
      req.body.gas,
      req.body.deposit,
      req.body.callbackUrl,
    )
    .then((result) => res.json(result))
    .catch(next);
};
