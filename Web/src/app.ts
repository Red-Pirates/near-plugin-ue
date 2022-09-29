import 'dotenv/config';
import express from 'express';
import cors from 'cors';
import { errorHandler } from './middleware/error.handler';
import swaggerUi from 'swagger-ui-express';
import YAML from 'yamljs';

import contractRoutes from './routes/contract.route';
import ftRoutes from './routes/ft-contract.route';
import nftRoutes from './routes/nft-contract.route';
import accountRoutes from './routes/account.route';
import loginRoutes from './routes/login.route';

export const PATH_PREFIX = '/api/v1';

const app = express();
const swaggerDocument = YAML.load('./openapi/near.yaml');

app.use(cors());
app.use(express.json());

app.use(`${PATH_PREFIX}/login`, loginRoutes);
app.use(`${PATH_PREFIX}/contracts`, contractRoutes);
app.use(`${PATH_PREFIX}/ft-contracts`, ftRoutes);
app.use(`${PATH_PREFIX}/nft-contracts`, nftRoutes);
app.use(`${PATH_PREFIX}/accounts`, accountRoutes);
app.use(`${PATH_PREFIX}/docs`, swaggerUi.serve, swaggerUi.setup(swaggerDocument));
app.use('/', swaggerUi.serve, swaggerUi.setup(swaggerDocument));

app.use(errorHandler);

export default app;
