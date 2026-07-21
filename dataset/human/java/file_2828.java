import java.io.InputStream;
import java.io.PrintWriter;
import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.math.MathContext;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
import java.util.TreeMap;
import java.util.TreeSet;

import static java.util.Comparator.*;

public class Main {
    public static void main(String[] args) {
        PrintWriter out = new PrintWriter(System.out);
        Solver solver = new Solver(System.in, out);
        solver.solve();
        out.close();
    }
}
class Solver {
	Scanner sc;
	PrintWriter out;
    public Solver(InputStream in, PrintWriter out) {
    	sc = new Scanner(in);
    	this.out = out;
    }
    // ==================================================================
    final long MOD = 1000000007;
    long[] NN = new long[100001];
    long[] diff = new long[100000];
    long modinv(long a, long m)	{	
		long b = m, u = 1, v = 0, wk;	
		while (b > 0) {	
			long t = a / b;
			a -= t * b; wk = a; a = b; b = wk;
			u -= t * v; wk = u; u = v; v = wk;
		}	
		u %= m; 	
		if (u < 0) u += m;	
		return u;	
	}		
    public void solve() {
    	int N = ni();
    	int x, sv = ni();
    	for (int i = 1; i < N; i++) {
			x = ni();
			diff[i-1] = x - sv;
			sv = x;
		}
    	NN[0] = 1;
    	for (int i = 1; i < N; i++) {
			NN[i] = (NN[i-1] * i) % MOD; 
		}
    	long ans = 0, wk = 0;
    	for (int i = 0; i < N; i++) {
//    		wk = (wk + NN[N-1]/(i+1)) % MOD;
    		wk = (wk + NN[N-1] * modinv((i+1), MOD)) % MOD;
			ans = (ans + (diff[i] * wk) % MOD) % MOD;
		}
    	out.println(ans);
	}
    static class PP{
    	public int key, val;
    	public PP(int key, int val) {
    		this.key = key;
    		this.val = val;
    	}
		public int getKey() {
			return key;
		}
		public void setKey(int key) {
			this.key = key;
		}
		public int getVal() {
			return val;
		}
		public void setVal(int val) {
			this.val = val;
		}
    }

    // ------------------------------------------
    // 入力
    // ------------------------------------------
    public int ni() {
    	return sc.nextInt();
    }
    public long nl() {
    	return sc.nextLong();
    }
    public String ns() {
    	return sc.next();
    }
    public char[] nc() {
    	return sc.next().toCharArray();
    }
    public int[] ndi(int N) {
    	int[] ans = new int[N];
    	for (int i = 0; i < N; i++) {
			ans[i] = ni();
		}
    	return ans;
    }
    public long[] ndl(int N) {
    	long[] ans = new long[N];
    	for (int i = 0; i < N; i++) {
			ans[i] = nl();
		}
    	return ans;
    }
    public String[] nds(int N) {
    	String[] ans = new String[N];
    	for (int i = 0; i < N; i++) {
			ans[i] = ns();
		}
    	return ans;
    }
    public char[][] ndc(int N) {
    	char[][] ans = new char[N][];
    	for (int i = 0; i < N; i++) {
			ans[i] = nc();
		}
    	return ans;
    }
    public int[][] nddi(int N, int S) {
    	int[][] ans = new int[N][S];
    	for (int i = 0; i < N; i++) {
			for (int j = 0; j < S; j++) {
				ans[i][j] = ni();
			}
		}
    	return ans;
    }
}
