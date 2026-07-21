import java.util.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{
    static final long mod=1000000007;
    static int dx[]={-1,0,1,0};
    static int dy[]={0,-1,0,1};

    public  static void main(String[] args)   throws Exception, IOException{        
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // char c[][] = new char[h][w];
        // char c[]=sc.nextString().toCharArray();
        // int d[]=new int[n];
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int a=sc.nextInt();
        int b=sc.nextInt();
        int c=sc.nextInt();
        long ans=b;
        if(c<=1+a+b)ans+=c;
        else {
        	ans+=a+b+1;
        }
        
//        long L=sc.nextLong();
//        int n=sc.nextInt();	
//        long a[]=new long[n];
//        for (int i = 0; i < a.length; i++) {
//			a[i]=sc.nextLong();
//		}
//        long d[]=new long[2*n+2];
//        for (int i = 0; i < n; i++) {
//			d[i+1]=a[i];
//			d[i+n+1]=a[i]+L;
//		}
//        
//        long dp[][][]=new long[2*n+3][2*n+3][2];
//        
//        
////        dp[0][n+1][n+1]=0;
////        dp[1][n+1][n+1]=0;
//        dp[n][n][0]=dp[n][n][1]=L-d[n];
//        dp[n+1][n+1][0]=dp[n+1][n+1][1]=d[n+1]-L;
//        long ans=0;
////        db(d);
//        for (int i = 1; i <= n-1 ; i++) {
//			for (int t = 1; t+i<=2*n ; t++) {
//				dp[t][t+i][0]=max(dp[t+1][t+i][0] + d[t+1]-d[t],
//						dp[t+1][t+i][1]+d[t+i]-d[t]);
//				dp[t][t+i][1]=max(dp[t][t+i-1][1] + d[t+i]-d[t+i-1],
//						dp[t][t+i-1][0]+d[t+i]-d[t]);
//				if(i==n-1) {
//					ans=max(ans,dp[t][t+i][0]);
//					ans=max(ans,dp[t][t+i][1]);
//				}
////				db(i,t,dp[t][t+i]);
//			}
//		}

        out.println(ans);
        out.flush();
    }
    
    static boolean validpos(int x,int y,int r, int c){
        return x<r && 0<=x && y<c && 0<=y;
    }


    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }  
}

class P {
    int id, d;
    P(int  id, int d) {
        this.id=id;
        this.d=d;
    }
}

//class P implements Comparable<P>{
//    int id, d;
//    P(int  id, int d) {
//        this.id=id;
//        this.d=d;
//    }
//    public int compareTo(P p){
//        return d-p.d; //des
//    }
//}

class Reader
{ 
    private BufferedReader x;
    private StringTokenizer st;
    
    public Reader(InputStream in)
    {
        x = new BufferedReader(new InputStreamReader(in));
        st = null;
    }
    public String nextString() throws IOException
    {
        while( st==null || !st.hasMoreTokens() )
            st = new StringTokenizer(x.readLine());
        return st.nextToken();
    }
    public int nextInt() throws IOException
    {
        return Integer.parseInt(nextString());
    }
    public int[] nextIntArray(int size) throws IOException{
    	int r[] = new int[size];
    	for (int i = 0; i < size; i++) {
			r[i] = this.nextInt(); 
		}
    	return r;
    }
    public long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    public double nextDouble() throws IOException
    {
        return Double.parseDouble(nextString());
    }
}
