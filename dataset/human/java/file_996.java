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
    // HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
    // ArrayList<Integer> lis = new ArrayList<Integer>();
    // ArrayList<Integer> map[]=new ArrayList[26];
    // static HashMap<Integer,Long> map = new HashMap<Integer,Long>();

    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // long n=sc.nextLong();
        // char c[][] = new char[h][w];
        // long a[] = new long [n];
        // char c[]=sc.nextString().toCharArray();
        // for(int i=0; i<n; i++) {a[i]=sc.nextInt();}
        int n=sc.nextInt();
        long c = sc.nextLong();
        long v[] = new long[n];
        long x[] = new long[n];
        long r[] = new long[n];
        long l[] = new long[n];
        long rr[] = new long[n];
        long ll[] = new long[n];

        for (int i=0; i<n; i++) {
            x[i] = sc.nextLong();
            v[i] = sc.nextLong();
        }

        for (int i=0,t=n-1; i<n; t--,i++) {
            r[i] = v[i] - x[i];
            if(i>0)r[i] += r[i-1] + x[i-1];
            l[i] = v[t] - (c - x[t]);
            if(i>0)l[i] += l[i-1] + (c - x[t+1]);

            rr[i] = r[i] - x[i];
            ll[i] = l[i] - (c - x[t]);
            if(i > 0){
                rr[i] = max(rr[i], rr[i-1]);
                ll[i] = max(ll[i], ll[i-1]);
            }
        }

        // db(r,l);
        // db(rr,ll);
        long ans = 0;
        for (int i=0; i<n; i++) {
            ans = max(ans,r[i]);
            if(n-i-2>=0)ans = max(ans,r[i] + ll[n-i-2]);
            // db(i, ans);
        }
        for (int i=0; i<n; i++) {
            ans = max(ans, l[i]);
            if(n-i-2>=0)ans = max(ans,l[i] + rr[n-i-2]);
            // db(i, ans);
        }

        out.println(ans);
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
