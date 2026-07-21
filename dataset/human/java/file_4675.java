import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main{

	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	void run(){
		long mod=100000007;
		for(;;){
			String s=sc.next();
			if(s.equals("#")){
				break;
			}

			int pm=-1;
			long res=1;
			long[] dp={1}, dp2=null;
			int n=1;
			s+="#";
			int k=0;
			for(char c : s.toCharArray()){
				int m=c-'0';
				if(m==pm){
					k++;
					for(int i=0; i<n; i++){
						dp2[i]=dp[i];
					}
					fill(dp, 0);
					for(int i=0; i<n; i++){
						if(i==n-1){
							if(k%n==0)
								dp[0]+=1;
						}else{
							dp[i+1]+=dp2[i];
						}
						dp[0]+=dp2[i];
					}
					for(int i=0; i<n; i++){
						dp[i]%=mod;
					}
				}else{
					long mul=0;
					for(int i=0; i<n; i++){
						mul+=dp[i];
					}
					res=res*mul%mod;
					if(m==8||m==0){
						n=3;
					}else{
						n=5;
					}
					dp=new long[n];
					dp2=new long[n];
					dp[0]=1;
					k=0;
				}
				pm=m;
				if(c=='#'){
					break;
				}
			}
			println(((int)res)+"");
		}
	}

	void debug(Object... os){
		// System.err.println(Arrays.deepToString(os));
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
