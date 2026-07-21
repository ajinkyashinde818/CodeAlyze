import java.util.*;
import java.io.*;
 
import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;
 
public class Main{
    static final long mod=1000000007;
    static int dx[]={1,-1,0,0};
    static int dy[]={0,0,1,-1};

    public  static void main(String[] args)   throws Exception, IOException{
        Reader sc = new Reader(System.in);
        PrintWriter out=new PrintWriter(System.out);
        // int n=sc.nextInt();
        // char c[][] = new char[h][w];
        // char c[]=sc.nextString().toCharArray();
        // int d[]=new int[n];
        // for(int i=0; i<n; i++) {d[i]=sc.nextInt();}

        int n=sc.nextInt();
        if(n<=2) {
        	if(n==1) {
                out.println("Yes");
                out.println(2);
                out.println(1+" "+1);
                out.println(1+" "+1);
                out.flush();
                return;        	        		
        	}
            out.println("No");
            out.flush();
            return;        	
        }
        int x=0,c=1;
        for (int i = 0; i < n; i++) {
        	x+=i;
        	db(x);
			if(x==n) {c=i+1;break;}
			else if(n<x) {
	            out.println("No");
	            out.flush();
	            return;        	
			}
		}
        ArrayList<Integer> l[]=new ArrayList[c];
        for (int i = 0; i < c; i++) {
        	l[i] = new ArrayList<Integer>(); 
        }        
        for (int i = 1,v=1; i <= c; i++) {
        	for (int t = i+1; t <= c; t++) {
				l[i-1].add(v); l[t-1].add(v++);
			}
        }

        out.println("Yes");
        out.println(c);
        for (int i = 0; i < c; i++) {
			out.print(c-1+" ");
            for (int t = 0; t < c-1; t++) {
				out.print(l[i].get(t)+" ");
			}       	
            out.println();
        }     
        
//        out.println();
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
