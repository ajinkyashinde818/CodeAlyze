import java.util.Scanner;

public class Main {
	static long fact[] = new long[300000];
	static long factInv[] = new long[300000];

	public static void main(String[] args) {
		final int MOD = 1_000_000_000 + 7;

		fact[0] = 1;
		factInv[0] = 1;
		for(int i = 0; i < fact.length - 1; i++){
			fact[i+1] = fact[i]*(i+1) % MOD; // n!(mod M)
	        factInv[i+1] = (int)(factInv[i]*repeatablePow(i+1, MOD-2, MOD) % MOD);
		}

		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();

		boolean broken[] = new boolean[n + 1];

		for(int i = 0; i < m; i++){
			broken[sc.nextInt()] = true;
		}

		//2連続で壊れていたらたどり着けない
		for(int i = 1; i < n; i++){
			if(broken[i] && broken[i - 1]){
				System.out.println(0);
				return;
			}
		}

		long result[] = new long[n + 1];
		result[0] = 1;

		if(!broken[1]){
			result[1] = 1;
		}
		for(int i = 2; i <= n; i++){
			if(broken[i]){
				result[i] = 0;
			}
			else {
				result[i] = (result[i - 1] + result[i - 2])%MOD;
			}
		}

		System.out.println(result[n]);
	}
	static long repeatablePow(int x, int n, int mod){
		if(n == 0){
			return 1;
		}
		long result = repeatablePow((int)((long)x*x%mod), n/2, mod);
		if(n % 2 == 1){
			result = result*x%mod;
		}
		return result;
	}


	//今回はnが大きすぎるがa,b<=2*10^5なのでこちらを使う
//	static long combination2(int n, int b, int mod){
//		if(b == 1){
//			return n;
//		}
//
//		long result = 1;
//
//		for(int i = 1; i <= b ; i++){
//			result *= (n - i + 1);
//			result %= mod;
//		}
//
//		result *= factInv[b];
//
//		return result % mod;
//	}
	static long combination(int a, int b, int mod){ //aCbをmod計算
	    if(a == 0 && b == 0)return 1;
	    if(a < b || a < 0)return 0;

	    long tmp = factInv[a - b]* factInv[b] % mod;
	    return tmp * fact[a] % mod;
	}
}
