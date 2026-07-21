import java.util.Scanner;

class MOD {
    static final int mod = 1000000007;

    static int add(int a, int b){
        int x = a + b;
        return (x >= mod) ? x - mod : x;
    }

    static int sub(int a, int b){
        int x = a - b;
        return (x < 0) ? x + mod : x;
    }

    static int mul(int a, int b){
        long x = (long)a * (long)b;
        return (int)(x % mod);
    }

    static int div(int a, int b){
        return mul(a, modinv(b));
    }

    static int modinv(int a) {
        int b = mod;
        int u = 1;
        int v = 0;
        while (b != 0) {
            int t = a / b;
            a -= t * b;
            int temp = a; a = b; b = temp; // swap(a, b)
            u -= t * v;
            temp = u; u = v; v = temp; // swap(u, v)
        }
        u %= mod;
        if (u < 0) u += mod;
        return u;
    }
}

public class Main {
    static Scanner stdIn = new Scanner(System.in);
    public static void main(String[] args){
		int n = stdIn.nextInt();
		int m = stdIn.nextInt();
		boolean[] crash = new boolean[n];
		for(int i=0; i<m; i++){
			int idx = stdIn.nextInt();
			crash[idx-1] = true;
		}

		int[] dp = new int[n];
		dp[0] = crash[0] ? 0 : 1;
		if(2 <= n)
			dp[1] = crash[1] ? 0 : dp[0] + 1;
		for(int i=2; i<n; i++){
			if(!crash[i-1]){
				dp[i] = dp[i-1];
			}
			if(!crash[i-2]){
				dp[i] = MOD.add(dp[i], dp[i-2]);
			}
		}

		System.out.println(dp[n-1]);
	}
}
