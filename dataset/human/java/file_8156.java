import java.io.*;
import java.math.BigInteger;
import java.util.*;

 
public class Main{
	/*
	 * use Integer for sorting
	 * avoid object comparison
	 * NEVER APPEND A STRING -> APPEND char by char
	 * Always use TreeSet instead of HashSet
	 * 
	 */
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
				} catch (Exception r) {
					r.printStackTrace();
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
			} catch (Exception r) {
				r.printStackTrace();
			}
			return str;
		}
	}
	
	public static PrintWriter out = new PrintWriter (new BufferedOutputStream(System.out));
	static long mod = (long) (1e9+7);
	static long cf = 998244353;
    static final long MAX = (long) 1e8;
    public static List<Integer>[] edges;
    public static int[][] parent;
    public static long[] fac;
    public static int N = 400000+200;
    public static int x = 0;
    public static boolean[] visited;
	public static void main(String[] args) {
		FastReader sc = new FastReader();
		
		long a = sc.nextLong();
		long b = sc.nextLong();
		long lcm = (a*b)/gcd(a,b);
		out.print(lcm);
		
		
		
		out.close();
	}
	private static long gcd(long a, long b) {
		if(b == 0) return a;
		return gcd(b,a%b);
	}
}
