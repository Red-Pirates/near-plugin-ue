# Near Plugin

Near plugin contains basic functionality for interacting with the Near blockchain from Unreal Engine 5.

## Features

- Sign in with Near 
- Check account balance 
- Check account state
- Check account details
- Deploy contract
- Creation of a new account
- Invoke contract View function
- Invoke contract Call function
- Creation of a transaction to invoke the payable contract method
- Get FT balance for account using [NEP-141](https://nomicon.io/Standards/Tokens/FungibleToken/Core)
- Get FT contract metadata using [NEP-148](https://nomicon.io/Standards/Tokens/FungibleToken/Metadata)
- Get NFT for owner, get NFT supply using [NEP-181](https://nomicon.io/Standards/Tokens/NonFungibleToken/Enumeration)
- Get NFT contract metadata using [NEP-177](https://nomicon.io/Standards/Tokens/NonFungibleToken/Metadata)
- Get NFT details using [NEP-171](https://nomicon.io/Standards/Tokens/NonFungibleToken/Core)

## Requirements

- [NEAR Account](https://docs.near.org/docs/develop/basics/create-account) 
- [Node.js](https://nodejs.org/en/download/)
- [Unreal Engine 5](https://www.epicgames.com/unrealtournament/en-US/download)

## How it works
The project contains two parts:
- Integration server, written in Node.js, which interacts with Near blockchain using near-api-js library.
- UE5 Plugin, which sends HTTP requests to the integration server and getting responses from it.

## Getting started

To get started, you need to start the integration server and connect the UE Near plugin, follow the instructions.

1. Clone repository

```bash
git clone git@gitlab.com:red-pirates/near-plugin.git
```

2. Place the NearPlugin directory in your project's Plugins directory.

3. Go to the Web directory and start the integration server, to do this follow the steps below.

### Node.js server setup

1. Install dependencies

```bash
npm install
```
2. Create .env file and set environment variables
```
NETWORK_ID=mainnet
CONTRACT_NAME=your_account.near
PRIVATE_KEY=your_account_private_key
```
3. Start server
```bash
npm start
```
#### You can also run tests, for that follow these steps:  

1. Create .test.env file and set test environment variables
```
NETWORK_ID=testnet
CONTRACT_NAME=your_test_account.testnet
PRIVATE_KEY=your_test_account_private_key
NEAR_NO_LOGS=true
```
2. Run tests
```bash
npm test
```
