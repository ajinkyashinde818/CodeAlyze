import java.io.*;
import java.util.*;
import java.awt.Point;
public class Main {
	static Scanner sc;
	static PrintWriter out;
	static class Edge implements Comparable<Edge>{
		int weight,from,to;
		public Edge(int u,int v,int w) {
			from = u;
			to = v;
			weight = w;
		}
		public String toString() {
			return (from+1)+" "+(to+1)+" "+weight;
		}
		@Override
		public int compareTo(Edge o) {
			// TODO Auto-generated method stub
			if(weight == o.weight)
				return from - o.from;
			return weight-o.weight;
		}
	}
	static Edge[] edges;
	static int[] parents;
	static int[]size;
	static int v,e;
	static Edge[] mst;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		sc = new Scanner(System.in); 
		out = new PrintWriter(System.out);
		int k = sc.nextInt();
		e = v = sc.nextInt();
		edges = new Edge[e*2];
		int[] vertix = new int[v];
		vertix[0] = sc.nextInt();
		for (int i = 1; i < v; i++) {
			vertix[i] = sc.nextInt();
			edges[i-1] = new Edge(i-1, i, vertix[i]-vertix[i-1]);
			edges[i-1+v] = new Edge(i, i-1, k-(vertix[i]-vertix[i-1]));
		}
		edges[v-1] = new Edge(0,  v-1, k-(vertix[v-1]-vertix[0]));
		edges[2*v-1] = new Edge(v-1, 0, (vertix[v-1]-vertix[0]));
//		System.out.println(Arrays.toString(edges));
		kruskals();
		out.println(res);
		out.close();
	}
	static final int uncal = -1;
	static final long inf = Long.MIN_VALUE;
	static boolean isPalindrome(String s) {
		int l = s.length();
		char[] sa = s.toCharArray();
		for(int i=0;i<l/2;i++) {
			if(sa[i] != sa[l-i-1])
				return false;
		}
		return true;
	}
	static int res = 0;
	static void kruskals() {
		mst = new Edge[v-1];
		Arrays.sort(edges);
		parents = new int[v];
		size = new int[v];
		for(int i=0;i<v;i++) {
			parents[i] = i;
			size[i] = 1;
		}
		int i,e;
		i = 0;e = 0;
		while(e < v-1) {
			Edge edge = edges[i++];
			if(isCycle(edge.from, edge.to))
				continue;
			union(find(edge.from),find(edge.to));
			mst[e] = edge;
			res += edge.weight;
			e++;
		}
	}
	static int find(int u) {
		if(parents[u] == u) {
			return u;
		}else {
			parents[u] = find(parents[u]);
			return parents[u];
		}
	}
	static void union(int u,int v) {
		u = find(u);
		v = find(v);
		if(size[u] > size[v]) {
			parents[v] = u;
			size[u] += size[v];
		}else {
			parents[u] = v;
			size[v] += size[u];
		}
	}
	static boolean isCycle(int u, int v) {
		return find(u) == find(v);
	}

	static String reverse(String s) {
		int i = s.length();
		StringBuilder sb = new StringBuilder();
		while(i-->0) {
			sb.append(s.charAt(i));
		}
		return sb.toString();
	}
	static void merge(StringBuilder sb,Stack<Character> stack) {
		while(!stack.isEmpty())
			sb.append(stack.pop());		
	}
	static String max(String s,String s2) {
		if(s2.length() > s.length())
			return s2;
		return s;
	}

	static class Point extends java.awt.Point implements Comparable<Point>{
		public Point(int x,int y) {
			// TODO Auto-generated constructor stub
			super(x,y);
		}
		public String toString() {
			return x+" "+y;
		}
		@Override
		public int compareTo(Point p) {
			// TODO Auto-generated method stub
			if(x == p.x)
				return y - p.y;
			return x - p.x;
		}
		
	}
	static class Scanner{
		private BufferedReader br;
		private StringTokenizer st;
		public Scanner(InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}
		public String next() throws IOException{
			while(st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}
		public String nextLine() throws IOException {
			return br.readLine();
		}
		public int nextInt() throws IOException{
			return Integer.parseInt(next());
		}
		public long nextLong() throws IOException{
			return Long.parseLong(next());
		}
		public double nextDouble() throws IOException{
			return Double.parseDouble(next());
		}
		public int[] inArr(int n) throws Exception{
			int a [] = new int[n];
			st = new StringTokenizer(br.readLine());
			for(int i=0;i<n;i++) {
				a[i] = Integer.parseInt(st.nextToken());
			}
			return a;
		}
	}

}
