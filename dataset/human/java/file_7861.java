import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {

	public static class FastReader {
		BufferedReader br;
		StringTokenizer root;
		
 
		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
 
		String next() {
			while (root == null || !root.hasMoreTokens()) {
				try {
					root = new StringTokenizer(br.readLine());
				} catch (Exception addd) {
					addd.printStackTrace();
				}
			}
			return root.nextToken();
		}
 
		int nextInt() {
			return Integer.parseInt(next());
		}
 
		double nextDouble() {
			return Double.parseDouble(next());
		}
 
		long nextLong() {
			return Long.parseLong(next());
		}
 
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (Exception addd) {
				addd.printStackTrace();
			}
			return str;
		}
	}
	
	public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
	
	public static FastReader sc = new FastReader();
 
	static int mod = (int) (1e9+7),MAX=(int) (2e5);
    static List<Integer>[] edges;
  
	public static void main(String[] args) {
	   
	    int n = sc.nextInt();
	    long k = sc.nextLong();
	    int[] a = new int[n+1];
	    boolean[] vis = new boolean[n+1];
	    for(int i=1;i<=n;++i) {
	    	a[i] = sc.nextInt();
	    }
	    int[] dis = new int[n+1];
	    int d = 1,cycle = 0;
	    int node = 1;
	    dis[node] = 1;
	    vis[node] = true;
	    int st = 1;
	    List<Integer> list = new ArrayList<Integer>();
	    list.add(1);
	    while(true) {
	    	node = a[node];
	    	if(vis[node]) {
	    		st = node;
	    		cycle = d-dis[node]+1;
	    		break;
	    	}else {
	    		++d;
	    		vis[node] = true;
	    		dis[node] = d;
	    		list.add(node);
	    	}
	    }
	  //  System.out.println(cycle+" "+d+" "+st+" "+list+" "+Arrays.toString(dis));
	 
	    int ans = 0;
	    if(k+1 <= d) {
	    	 ans = list.get((int) k);
	    }else {
	    	k-=d;
	    	k%=cycle;
	    	boolean found = false;
	    	for(int i=0;i<list.size();++i) {
	    		if(list.get(i) == st)  found = true;
	    		if(found) {
	    		
	    			if(k == 0) {
	    				ans = list.get(i);
	    				break;
	    			}
	    			--k;
	    		}
	    	}
	    }
	    out.print(ans);
		out.close();
   }
	
	
}
