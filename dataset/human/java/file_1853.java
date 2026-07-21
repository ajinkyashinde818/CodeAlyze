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
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        // int n=sc.nextInt();
        int d=sc.nextInt(),n=d;
        int g=sc.nextInt();
        int p[] = new int[n];
        int c[] = new int[n];

        for(int i=0; i<n; i++) {
            p[i]=sc.nextInt();
            c[i]=sc.nextInt();
        }
        int ans=1<<28;
        for(int i=0; i<1<<n; i++) {
            int x=0,s=0;
            int e[]=new int[n];
            for (int t=0; t<n; t++ ) {
                if( ((i>>t)&1)==1 ){x+=p[t]; s+=p[t]*(t+1)*100+c[t]; e[t]++;}
            }
            if(s>=g){ans=min(ans,x); continue;}
            lp:for (int t=n-1; -1<t; t-- ) {
                if(e[t]>0)continue;
                for (int w=1; w<=p[t]; w++) {
                    s+=100*(t+1);
                    x++;
                    if(g<=s){ans=min(ans,x); break lp;}
                }
            }
        }

        out.println(ans);
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
        return Integer.compare(d,p.d); //des
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
