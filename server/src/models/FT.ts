export interface NearFTMetadata {
  spec: string;
  name: string;
  symbol: string;
  icon: string | null;
  reference: string | null;
  reference_hash: string | null;
  decimals: number;
}

export interface FTBalanceResponse {
  tokenName: string;
  symbol: string;
  icon: string | null;
  balance: string;
}

export interface GetFTAccountBalanceRequest {
  contractId: string;
  accountId: string;
}

export interface GetFTTotalBalanceRequest {
  contractId: string;
}
