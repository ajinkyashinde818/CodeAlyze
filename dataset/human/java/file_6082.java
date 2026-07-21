import java.io.IOException; 
import java.io.InputStream; 
import java.io.PrintWriter; 

class Main{
	static long[][] comb = new long[4010][4010];
	static long mod = 998244353;
	static long[][] dp = new long[2020][2020];
	static int k;
	static long H(int r, int n){
		if(r==0)return n==0 ? 1:0;
		return comb[n+r-1][n];
	}

	// 1<=p<=k
	static long culc(int n, int p){
		long res = 0;
		long presum = 0;
		for(int l=0;l<=n;++l){
			if(p%2==0){
				dp[p/2][l] = (dp[p/2-1][l] + presum*2%mod)%mod;
				presum =(presum + dp[p/2-1][l])%mod;
			}
			res = (res + dp[p/2][l]*H(k-p, n-l)%mod)%mod;
		}
		return res;
	}

	static void solve(){
		k = ni();
		int n=ni();
		comb[0][0]=1;
		for(int i=1;i<=n+k;++i){
			comb[i][0]=1;
			for(int j=1;j<=i;++j){
				comb[i][j] = (comb[i-1][j-1]+comb[i-1][j])%mod;
			}
		}

		dp[0][0]=1;
		for(int i=2;i<=2*k;++i){
			int p = Math.min(i-1, 2*k-i+1);
			if(i%2==0){
				out.println((culc(n-1, p) + culc(n, p))%mod);
			}else out.println(culc(n, p));
		}
	} 
 
 
 
 
	public static void main(String[] args){ 
		 solve(); 
		 out.flush(); 
	 } 
	 private static InputStream in = System.in; 
	 private static PrintWriter out = new PrintWriter(System.out); 
 
	 private static final byte[] buffer = new byte[1<<15]; 
	 private static int ptr = 0; 
	 private static int buflen = 0; 
	 private static boolean hasNextByte(){ 
		 if(ptr<buflen)return true; 
		 ptr = 0; 
		 try{ 
			 buflen = in.read(buffer); 
		 } catch (IOException e){ 
			 e.printStackTrace(); 
		 } 
		 return buflen>0; 
	 } 
	 private static int readByte(){ if(hasNextByte()) return buffer[ptr++]; else return -1;} 
	 private static boolean isSpaceChar(int c){ return !(33<=c && c<=126);} 
	 private static int skip(){int res; while((res=readByte())!=-1 && isSpaceChar(res)); return res;} 
 
	 private static double nd(){ return Double.parseDouble(ns()); } 
	 private static char nc(){ return (char)skip(); } 
	 private static String ns(){ 
		 StringBuilder sb = new StringBuilder(); 
		 for(int b=skip();!isSpaceChar(b);b=readByte())sb.append((char)b); 
		 return sb.toString(); 
	 } 
	 private static int[] nia(int n){ 
		 int[] res = new int[n]; 
		 for(int i=0;i<n;++i)res[i]=ni(); 
		 return res; 
	 } 
	 private static long[] nla(int n){ 
		 long[] res = new long[n]; 
		 for(int i=0;i<n;++i)res[i]=nl(); 
		 return res; 
	 } 
	 private static int ni(){ 
		 int res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	 } 
	 private static long nl(){ 
		 long res=0,b; 
		 boolean minus=false; 
		 while((b=readByte())!=-1 && !((b>='0'&&b<='9') || b=='-')); 
		 if(b=='-'){ 
			 minus=true; 
			 b=readByte(); 
		 } 
		 for(;'0'<=b&&b<='9';b=readByte())res=res*10+(b-'0'); 
		 return minus ? -res:res; 
	} 
}
