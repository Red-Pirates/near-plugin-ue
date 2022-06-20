import { NextFunction, Request, Response } from 'express';
import { loginService } from '../service/login.service';

export const loginSuccess = (req: Request, res: Response, next: NextFunction): void => {
  console.log(req.query);
  loginService
    .loginSuccess(req.query.account_id as string)
    .then(() => res.send('Login successful, you can go back to the game.'))
    .catch(next);
};

export const loginFailed = (req: Request, res: Response, next: NextFunction): void => {
  console.log(req.query);
  loginService
    .loginFailed()
    .then(() => res.send('Login failed :('))
    .catch(next);
};
