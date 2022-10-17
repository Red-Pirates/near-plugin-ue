export interface FtMetadata {
  spec: string;
  name: string;
  symbol: string;
  icon: string | null;
  reference: string | null;
  referenceHash: string | null;
  decimals: number;
}

export interface FtBalanceResponse {
  balance: string;
}
