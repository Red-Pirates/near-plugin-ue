import 'dotenv/config';
import express from 'express';
import cors from 'cors';
import { errorHandler } from './middleware/error.handler';

import authRoutes from './routes/auth.route';
import accountRoutes from './routes/account.route';
import nftRoutes from './routes/nft.route';
import ftRoutes from './routes/ft.route';

export const PATH_PREFIX = '/api/v1';

const app = express();

app.use(cors());
app.use(express.json());

app.use(`${PATH_PREFIX}/auth`, authRoutes);
app.use(`${PATH_PREFIX}/account`, accountRoutes);
app.use(`${PATH_PREFIX}/nft`, nftRoutes);
app.use(`${PATH_PREFIX}/ft`, ftRoutes);

app.use(errorHandler);

export default app;
