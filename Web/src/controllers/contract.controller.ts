import { NextFunction, Request, Response } from 'express';
import { contractService } from '../service/contract.service';

interface ContractParams {
  contractId: string;
}

interface DeployContractBody {
  fileName: string;
}

export const deployContract = (
  req: Request<never, never, DeployContractBody>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .deployContract(req.body.fileName)
    .then(() => res.sendStatus(204))
    .catch(next);
};

interface ViewFunctionBody extends ContractParams {
  method: string;
  params: Record<string, any>;
}

export const invokeViewFunction = (
  req: Request<never, never, ViewFunctionBody>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .callViewContractFunction(req.body.contractId, req.body.method, req.body.params)
    .then((result) => res.json(result))
    .catch(next);
};

interface CallFunctionBody extends ContractParams {
  accountId: string;
  secretKey: string;
  method: string;
  params: Record<string, any>;
  attachedGas?: string;
  attachedTokens?: string;
}

export const callContractFunction = (
  req: Request<never, never, CallFunctionBody>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .callCallContractFunction(
      req.body.accountId,
      req.body.secretKey,
      req.body.contractId,
      req.body.method,
      req.body.params,
      req.body.attachedGas,
      req.body.attachedTokens,
    )
    .then((result) => res.json(result))
    .catch(next);
};

export const getLoginUrl = (
  req: Request<ContractParams>,
  res: Response,
  next: NextFunction,
): void => {
  contractService
    .createLoginWalletUrl(req.params.contractId)
    .then((result) => res.json(result))
    .catch(next);
};

interface TransactionUrlBody {
  signerId: string;
  receiverId: string;
  method: string;
  params: Record<string, any>;
  gas: string;
  deposit: string;
  callbackUrl: string;
}

export const getTransactionUrl = (
  req: Request<never, never, TransactionUrlBody>,
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
