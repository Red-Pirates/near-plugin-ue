import * as WebSocket from 'ws';
import { wss } from '../webSocketServer';

class LoginService {
  loginSuccess = async (accountId: string) => {
    console.log('login success');
    console.log(accountId);
    wss.clients.forEach((client) => {
      if (client.readyState === WebSocket.OPEN) {
        client.send(accountId);
        client.close();
      }
    });
  };

  loginFailed = async () => {
    console.log('login failed');
    wss.clients.forEach((client) => {
      if (client.readyState === WebSocket.OPEN) {
        client.close();
      }
    });
  };
}

export const loginService = new LoginService();
