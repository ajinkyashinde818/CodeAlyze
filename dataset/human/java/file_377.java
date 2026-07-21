/*
 * Code Author: Akshay Miterani
 * DA-IICT
 */
import java.io.*;
import java.math.BigInteger;
import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.*;

public class Main {

	static double eps=(double)1e-10;
	static long mod=(long)1e9+7;
	static final long INF = Long.MAX_VALUE / 100;
	public static void main(String args[]) throws FileNotFoundException{
		InputReader in = new InputReader(System.in);
		OutputStream outputStream = System.out;
		PrintWriter out = new PrintWriter(outputStream);
		//----------------My Code------------------
		double xs=in.nextInt();
		double ys=in.nextInt();
		double xt=in.nextInt();
		double yt=in.nextInt();
		int n=in.nextInt();
		double p[][]=new double[n+2][3];
		for(int i=0;i<n;i++){
			p[i][0]=in.nextInt();
			p[i][1]=in.nextInt();
			p[i][2]=in.nextInt();
		}
		p[n][0]=xs;
		p[n][1]=ys;
		p[n][2]=0;
		p[n+1][0]=xt;
		p[n+1][1]=yt;
		p[n+1][2]=0;
		List<Edge>[] edges = new List[n+2];
		for (int i = 0; i < n+2; i++) {
		      edges[i] = new ArrayList<>();
		}
		for(int i=0;i<n+2;i++){
			for(int j=0;j<n+2;j++){
				edges[i].add(new Edge(j, md(p[i], p[j])));
			}
		}
		double ans[]=new double[n+2];
		shortestPaths(edges, n, ans);
		out.printf("%.10f\n",ans[n+1]);
		out.close();
		//----------------The End------------------

	}
	static double md(double p1[], double p2[]){
		return Math.max(0, dist(p1[0], p1[1], p2[0], p2[1])-p1[2]-p2[2]);
	}
	static double dist(double x1,double y1,double x2,double y2){
		return Math.sqrt(Math.pow(x1-x2,2)+Math.pow(y1-y2, 2));
	}
	public static void shortestPaths(List<Edge>[] edges, int s, double[] prio) {
		Arrays.fill(prio, INF);
		prio[s] = 0;
		PriorityQueue<Pair> q = new PriorityQueue<>(100, new cmp());
		q.add(new Pair(0, s));
		while (!q.isEmpty()) {
			Pair cur = q.remove();
			int curu = cur.p;
			if (Math.abs(cur.x-prio[curu])>eps)
				continue;
			for (Edge e : edges[curu]) {
				int v = e.t;
				double nprio = prio[curu] + e.cost;
				if (prio[v] > nprio) {
					prio[v] = nprio;
					q.add(new Pair(nprio, v));
				}
			}
		}
	}
	static class cmp implements Comparator<Pair>{

		@Override
		public int compare(Pair o1, Pair o2) {
			return Double.compare(o1.x, o2.x);
		}
		
	}
	static class Edge {
		int t;
		double cost;

		public Edge(int t, double cost) {
			this.t = t;
			this.cost = cost;
		}
	}
	static long modulo(long a,long b,long c) {
		long x=1;
		long y=a;
		while(b > 0){
			if(b%2 == 1){
				x=(x*y)%c;
			}
			y = (y*y)%c; // squaring the base
			b /= 2;
		}
		return  x%c;
	}
	static long gcd(long x, long y)
	{
		if(x==0)
			return y;
		if(y==0)
			return x;
		long r=0, a, b;
		a = (x > y) ? x : y; // a is greater number
		b = (x < y) ? x : y; // b is smaller number
		r = b;
		while(a % b != 0)
		{
			r = a % b;
			a = b;
			b = r;
		}
		return r;
	}
	static class Pair implements Comparable<Pair>{
		double x;
		int p;
		Pair(double xx,int pp){
			x=xx;
			p=pp;
		}
		@Override
		public int compareTo(Pair o) {
			return Double.compare(this.x, o.x);
		}
	}
	public static void debug(Object... o) {
		System.out.println(Arrays.deepToString(o));
	}
	static class InputReader {
		public BufferedReader reader;
		public StringTokenizer tokenizer;

		public InputReader(InputStream inputstream) {
			reader = new BufferedReader(new InputStreamReader(inputstream));
			tokenizer = null;
		}

		public String nextLine(){
			String fullLine=null;
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					fullLine=reader.readLine();
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
				return fullLine;
			}
			return fullLine;
		}
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(reader.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		public long nextLong() {
			return Long.parseLong(next());
		}
		public int nextInt() {
			return Integer.parseInt(next());
		}
	}
}
