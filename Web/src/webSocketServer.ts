import * as WebSocket from 'ws';
export const wss = new WebSocket.Server({ port: 5000 });

wss.on('connection', (ws: WebSocket) => {
  console.log('Received connection from UE4 WebSocket client.');

  ws.on('message', (message) => {
    console.log('Received message from UE4 WebSocket client: %s.', message);
  });

  ws.on('close', () => {
    console.log('Connection closed');
  });
});
