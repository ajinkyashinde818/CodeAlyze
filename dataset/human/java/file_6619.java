import java.util.*;
import java.io.*;
import java.math.*;
 
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{ 
 
 
    static long mod=1000000007;
    static int dx[]={1,-1,0,0};
    static int dy[]={0,0,1,-1};
    // static int dx[]={1,-1,0,0,1,1,-1,-1};
    // static int dy[]={0,0,1,-1,1,-1,1,-1};
    // PriorityQueue<Integer> que = new PriorityQueue<Integer>(); 
    //HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
 
    public  static void main(String[] args)   throws Exception, IOException{
     
        
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
     
        // int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // for (int i=0; i<n; i++ ) {a[i]=sc.nextInt();}
        long ans=0;
        char c[] = sc.nextString().toCharArray();
        int X=sc.nextInt()+8001;
        int Y=sc.nextInt()+8001;
        int x[] = new int[8001];
        int y[] = new int[8001];
        int d = 0, w = 0,xg=0,yg=0, n=c.length;
        for (int i=0 ; i < n; i++) {
            d = 0;
            if(c[i]=='T'){w++;continue;}
            while(i<n &&  c[i]=='F'){d++; i++;}
            if(w%2==0){
                x[xg++] = d;
            }
            else{
                y[yg++] = d;
            }
            i--;
        }

        int dp[][]=new int[xg+10][16050],f=0,st=1;
        dp[0][8001]=1;
        if(c[0]=='F'){
            st=2;
            dp[1][x[0]+8001]++;
        }
        for (int i=st; i<=xg; i++) {
            for (int t=0; t<16010; t++) {
                if(dp[i-1][t]>0){
                    dp[i][t+x[i-1]]++;
                    dp[i][t-x[i-1]]++;
                }
            }
        }
        if(dp[xg][X]>0)f++;

        dp=new int[yg+1][16050];
        dp[0][8001]=1;
        for (int i=1; i<=yg; i++) {
            for (int t=0; t<16010; t++) {
                if(dp[i-1][t]>0){
                    dp[i][t+y[i-1]]++;
                    dp[i][t-y[i-1]]++;
                }
            }
        }
        if(dp[yg][Y]>0)f++;
        out.println(f>1 ? "Yes":"No");
        out.flush();
    }

    static void db(Object... os){
     
        System.err.println(Arrays.deepToString(os));
     
    }
     
    static boolean validpos(int x,int y,int r, int c){
        
        return x<r && 0<=x && y<c && 0<=y;
        
    }
     
    static boolean bit(long x,int k){
        // weather k-th bit (from right) be one or zero
        return  ( 0 < ( (x>>k) & 1 )  )  ? true:false;
    }    
}

class XY {
    int x,y,d;
    XY(int x, int y, int d) {
        this.x=x;
        this.y=y;
        this.d=d;
    } 
}
 
class P implements Comparable<P>{
    int x,y;
    P(int x, int y) {
        this.x=x;
        this.y=y;
    } 
      
    public int compareTo(P p){
        return -x + p.x;//des
    } 
}
 
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
    public long nextLong() throws IOException
    {
        return Long.parseLong(nextString());
    }
    public double nextDouble() throws IOException
    {
        return Double.parseDouble(nextString());
    }
}
