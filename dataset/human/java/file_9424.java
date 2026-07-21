import java.util.*;
import java.io.*;

public class Main
{
    static class Reader {
		BufferedReader br;
		StringTokenizer st;
 
		public Reader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
 
	}
    static class Ele implements Comparable<Ele> 
    {  
        public int x,y;  
        Ele(int x,int y) 
        {  
            this.x=x;this.y=y; 
        }  
        public int compareTo(Ele ob) {  
        if(ob.x!=x)return x-ob.x;
        return this.y-ob.y;  
        }   
    }
    int a[][];int b[][];
    
    long gcd(long a,long b)
    {
        long min=Math.min(a,b);
        long max=Math.max(a,b);
        while (max%min!=0)
        {
            a=max%min;
            max=min;min=a;
        }
        return min;
    }
	public static void main(String[] args) throws IOException 
	{
		Reader sc=new Reader();Main G=new Main();
		PrintWriter o = new PrintWriter(System.out);
		int t=1;//t=sc.nextInt();
		int x,x0,x1,x2;int y,y0,y1,y2;int s,s0,s1,s2;
		int n,m;int a[],b[],in[],in1[];
		long k,l;boolean b1,b2;String ss1[],ss;
		//long l;long a[]; 
		ArrayList<ArrayList<Integer>> ll=new ArrayList<>();
		ArrayList<Integer> a1=new ArrayList<>();
		ArrayList<Integer> a2=new ArrayList<>();
		ArrayList<Integer> a3=new ArrayList<>();
		ArrayDeque<Integer> deq=new ArrayDeque<>();
		TreeSet<Integer> h0=new TreeSet<>();
		TreeSet<Integer> h1=new TreeSet<>();
		HashMap<Integer,Integer> h=new HashMap<>();
		try{
		while (t-->0)
		{
		    n=sc.nextInt();s=0;b1=false;
		    while (n-->0)
		    {
		        x=sc.nextInt();y=sc.nextInt();
		        if (x==y)s++;
		        else s=0;
		        if (s>=3) b1=true;
		    }
		    if (b1)o.println("Yes");
		    else o.println("No");
		    //o.println(h);
		    //o.println(x2);
		    //o.println();
		    h0.clear();ll.clear();a1.clear();a2.clear();h1.clear();
		}
		}
		catch (Throwable e)
		{
		    e.printStackTrace();
		}
		//o.println("HI");
		
        o.flush();
        o.close();
	}
}
