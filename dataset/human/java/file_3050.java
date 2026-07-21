import java.io.*;
import java.math.*;
import java.util.*;
public class Main { 
 
	public static void main(String[] args) { //X^0=X, therefore for null case, return 0
		FastScanner I = new FastScanner(); //Input
		OutPut O = new OutPut(); //Output
		int N = I.nextInt();
		int M = I.nextInt();
		ArrayList<Integer>[] graph = new ArrayList[N+1];
		for (int i = 1; i <= N; i++) graph[i] = new ArrayList<Integer>();
		for (int i = 0; i < M; i++) {
			int A = I.nextInt();
			int B = I.nextInt();
			graph[A].add(B);
			graph[B].add(A);
		}
		O.pln(BFS(graph,N)?"POSSIBLE":"IMPOSSIBLE");
	}
	public static boolean BFS(ArrayList<Integer>[] graph, int N) {
		boolean[] vis = new boolean[N+1];
		vis[1]=true;
		Queue<Integer> cur = new LinkedList<Integer>();
		cur.add(1);
		int cnt = 0; //How many services used so far in quest
		while (!cur.isEmpty()) {
			int size = cur.size();
			for (int i = 0; i < size; i++) {
				int curIsland = cur.poll();
				for (int j = 0; j < graph[curIsland].size(); j++) {
					int nbr = graph[curIsland].get(j);
					if (!vis[nbr]) {
						cur.add(nbr);
						vis[nbr]=true;
						if (nbr==N) return true;
					}
				}
			}
			cnt++;
			if (cnt>=2) break;
		}
		return false;
	}
	public static void build(long[] segtree, long[] a, int start, int end, int node) {
		if (start==end) segtree[node] = a[start];
		else{ //Need else statements for void methods
			int mid = (start+end)/2;
			build(segtree,a,start,mid,2*node); //Build from left child onwards
			build(segtree,a,mid+1,end,2*node+1); //Build from right child onwards
			segtree[node] = segtree[2*node]^segtree[2*node+1]; //Current node stores XOR of children
			//(Order of XOR doesn't matter, just occurrences of 1 bit in a certain slot
		}
	}
	public static long getXOR(long[] segtree, long[] a, int start, int end, int L, int R, int node) {
		if (R<start||L>end) return 0; //Returning answer that has no effect on final answer
		if (L<=start&&R>=end) return segtree[node]; //If range encapsulates current node of 
		//segment tree
		int mid = (start+end)/2; //Partial case --> Recurse deeper into segment tree
		long left = getXOR(segtree,a,start,mid,L,R,node*2);
		long right = getXOR(segtree,a,mid+1,end,L,R,2*node+1);
		return left^right;
	}
	public static long ceil(long num, long den) {long ans = num/den; if (num%den!=0) 
	ans++; return ans;}
	public static long GCD(long a, long b) {
		if (a==0||b==0) return Math.max(a,b);
		return GCD(Math.min(a, b),Math.max(a, b)%Math.min(a, b));
	}
	public static long FastExp(long base, long exp, long mod) {
		long ans=1;
		while (exp>0) {
			if (exp%2==1) ans*=base;
			exp/=2;
			base*=base;
			base%=mod;
			ans%=mod;
		}
		return ans;
	}
	public static long ModInv(long num,long mod) {return FastExp(num,mod-2,mod);}
	public static int pop(long x) { //Returns number of bits within a number
		int cnt = 0;
		while (x>0) {
			if (x%2==1) cnt++;
			x/=2;
		}
		return cnt;
	}
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		int nextInt() {return Integer.parseInt(next());}
		long nextLong() {return Long.parseLong(next());};
	}
	static class OutPut{
		PrintWriter w = new PrintWriter(System.out);
		void pln(int x) {w.println(x);w.flush();}
		void pln(long x) {w.println(x);w.flush();}
		void pln(String x) {w.println(x);w.flush();}
		void pln(char x) {w.println(x);w.flush();}
		void pln(StringBuilder x) {w.println(x);w.flush();}
		void pln(BigInteger x) {w.println(x);w.flush();}
		void p(int x) {w.print(x);w.flush();}
		void p(long x) {w.print(x);w.flush();}
		void p(String x) {w.print(x);w.flush();}
		void p(char x) {w.print(x);w.flush();}
		void p(StringBuilder x) {w.print(x);w.flush();}
		void p(BigInteger x) {w.print(x);w.flush();}
	}
}
