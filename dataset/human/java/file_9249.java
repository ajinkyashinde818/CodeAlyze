import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	static Scanner scanner;
	static long[][] dp;
    static int ind=1;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    int n=gi();
	    int m=gi();
        boolean[] f=new boolean[n+1];
        int[] a=new int[m];
        dp=new long[2][n+1];
        dp[0][1]=1;
        dp[1][1]=1;
        f[0]=true;
        f[n]=true;

        for (int i=0; i<m;i++) {
            a[i]=gi();
            f[a[i]]=true;
            f[a[i]-1]=true;
            f[a[i]+1]=true;
            if(i!=0 && a[i]-a[i-1] == 1) {
            	System.out.println(0);
            	return;
            }
        }

        long c=0;
        List<Long> l = new ArrayList<Long>();
        for (int i=0; i<n+1;i++) {
            if(c!=0 && f[i]) {
            	l.add(c);
            	c=0;
            } else if(!f[i]) {
            	c++;
            }
        }

        long ans=1;
        for (int i=0; i<l.size();i++) {
        	long j=l.get(i);
        	ans = (ans*gv(j)) % 1000000007l;
        }

        System.out.println(ans);
	}

	public static long gv(long v) {
		if(ind>=v) {
			return (dp[0][(int)v]+dp[1][(int)v]) % 1000000007l;
		}

		for (int i=ind+1; i<=v; i++) {
			dp[0][i]=dp[1][i-1];
			dp[1][i]=(dp[0][i-1] +dp[1][i-1]) % 1000000007l;
		}
		ind=(int)v;
		return (dp[0][(int)v]+dp[1][(int)v]) % 1000000007l;
	}

	// a^nをmodで割ったあまり
	public static long modpow(long a, long n, long mod) {
		long res=1;
		while(n>0) {
			if((n & 1) == 1) res=res*a%mod;
			a=a*a%mod;
			n=n>>1;
		}

		return res;
	}

	// 文字列として入力を取得
	public static String gs() {
		return scanner.next();
	}

	// intとして入力を取得
	public static int gi() {
		return Integer.parseInt(scanner.next());
	}

	// longとして入力を取得
	public static long gl() {
		return Long.parseLong(scanner.next());
	}

	// doubleとして入力を取得
	public static double gd() {
		return Double.parseDouble(scanner.next());
	}
}
