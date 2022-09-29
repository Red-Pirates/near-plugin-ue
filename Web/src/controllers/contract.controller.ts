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
    .invokeViewFunction(req.body.contractId, req.body.method, req.body.params)
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
