import java.util.*;
import java.io.*;
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{
    static final long mod=1000000007;
    
    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // char c[][] = new char[h][w];
        // char c[]=sc.nextString().toCharArray();
        // int d[]=new int[n];
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int k=sc.nextInt();
        int n=sc.nextInt();

        int sz=4001;
        long fr[]=new long[sz];
        long inv[]=new long[sz];

        fr[0]=inv[0] = 1;
        fr[1]=inv[1] = 1;
        int mod=998244353;

        for (int i = 2; i <sz; ++i){
            inv[i] = inv[mod % i] * (mod - mod / i) % mod ;
        }

        for (int i = 2; i <sz; ++i){
            fr[i]=fr[i-1]*i %mod;
            inv[i]=inv[i-1]*inv[i] %mod;
        }

        long b[]=new long[sz];
        b[0]=1;
        for (int i = 1; i <sz; ++i){
            b[i]=b[i-1]*2;
            b[i]%=mod;
        }

        for (int i=2; i<=2*k; i++) {
            int g=(i-1)/2,s;
            long f=0,e=0,ans=0;

            if(i>k)g= (k-(i-k-1))/2;
            s=k-g*2;
            // db(i,g,s);
            if(i%2==0){
                s--;
                for (int t=0; t<=g; t++) {
                    if(t+s-1<0||n-t<0)continue;
                    e=fr[n+s-1]*inv[t+s-1]%mod;
                    e*=inv[n-t]; e%=mod;
                    e*=b[t]; e%=mod;
                    e*=fr[g]*inv[t]%mod; e%=mod;
                    e*=inv[g-t]; e%=mod;
                    // db(i,t,e);
                    f+=e; f%=mod; e=0;
                }
                for (int t=0; t<=g; t++) {
                    if(t+s-1<0 || n-1+s-1<0 || n-t-1<0)continue;
                    e=fr[n-1+s-1]*inv[t+s-1]%mod;
                    e*=inv[n-t-1]; e%=mod;
                    e*=b[t]; e%=mod;
                    e*=fr[g]*inv[t]%mod; e%=mod;
                    e*=inv[g-t]; e%=mod;
                    // db(i,t,e);
                    f+=e; f%=mod; e=0;
                }
                ans=f;
            }
            else {
                for (int t=0; t<=g; t++) {
                    if(t+s-1<0||n-t<0)continue;
                    e=fr[n+s-1]*inv[t+s-1]%mod;
                    e*=inv[n-t]; e%=mod;
                    e*=b[t]; e%=mod;
                    e*=fr[g]*inv[t]%mod; e%=mod;
                    e*=inv[g-t]; e%=mod;
                    f+=e; f%=mod; e=0;
                }
                ans=f;
            }
            // db(i,g,s,f);
            out.println(ans);
        }




        // out.println(ans);
        out.flush();
    }


    static void db(Object... os){
        System.err.println(Arrays.deepToString(os));
    }  
}

class P implements Comparable<P>{
    int id, d;
    P(int  id, int d) {
        this.id=id;
        this.d=d;
    }
    public int compareTo(P p){
        return d-p.d; //des
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
