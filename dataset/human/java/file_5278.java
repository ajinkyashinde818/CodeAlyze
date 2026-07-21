import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

// AC
public class Main{

	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int n=10;
	int[][] a;

	void run(){
		for(;;){
			n=sc.nextInt();
			if(n==0){
				break;
			}
			a=new int[n][n];
			for(int j=0; j<n; j++){
				String s=sc.next();
				for(int i=0; i<n; i++){
					a[j][i]=s.charAt(i)=='.'?0:1;
				}
			}
			solve();
		}
	}

	void solve(){
		int[][] dp=new int[n][n];
		int max=0;
		for(int j=0; j<n; j++){
			for(int i=0; i<n; i++){
				if(a[j][i]==0){
					if(i>0&&j>0){
						int n=Math.min(dp[j-1][i-1],
								Math.min(dp[j][i-1], dp[j-1][i]));
						dp[j][i]=n+1;
					}else{
						dp[j][i]=1;
					}
				}else{
					dp[j][i]=0;
				}
				max=Math.max(max, dp[j][i]);
			}
		}
		println(""+max);
	}

	void debug(Object... os){
		System.err.println(Arrays.deepToString(os));
	}

	void print(String s){
		System.out.print(s);
	}

	void println(String s){
		System.out.println(s);
	}

	public static void main(String[] args){
		// System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		new Main().run();
	}
}
