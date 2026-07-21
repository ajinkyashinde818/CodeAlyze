/*
javac Main.java && java Main
*/

import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
	public static void main(String[] args) { new Main(); }
	FS in = new FS();
	PrintWriter out = new PrintWriter(System.out);

	int n, q, x, a, b;
	char[] s, ss;

	Main() {
		ss = in.next().toCharArray();
		n = ss.length;

		q = in.nextInt();
		s = new char[q + n + q];
		for (int i = q; i < q + n; i++)
			s[i] = ss[i - q];
		a = n + q - 1; b = q;
		
		x = 0;
		int t, f; char c;
		int qq = q, y = 0;
		while (qq-- > 0) {
			t = in.nextInt();
			if (t == 1) x ^= 1;
			else {
				y++;
				f = in.nextInt();
				c = in.next().charAt(0);

				if (f == 1) {
					if (x == 1) s[++a] = c;
					else s[--b] = c;
				}
				else {
					if (x == 1) s[--b] = c;
					else s[++a] = c;
				}
			}
		}
		
		char[] ans = new char[a - b + 1];
		if (x == 0) {
			x = 0;
			for (int i = b; i <= a; i++)
				ans[x++] = s[i];
		}
		else {
			x = 0;
			for (int i = a; i >= b; i--)
				ans[x++] = s[i];
		}
		out.println(new String(ans));
		out.close();
	}

	
	
	int abs(int x) { if (x < 0) return -x; return x; }
	long abs(long x) { if (x < 0) return -x; return x; }
	int max(int x, int y) { if (x < y) return y; return x; }
	int min(int x, int y) { if (x > y) return y; return x; }
	long max(long x, long y) { if (x < y) return y; return x; }
	long min(long x, long y) { if (x > y) return y; return x; }
	int gcd(int x, int y) { while (y > 0) { x = y^(x^(y = x)); y %= x; } return x; }
	long gcd(long x, long y) { while (y > 0) { x = y^(x^(y = x)); y %= x; } return x; }
	long lcm(int x, int y) { return ((long) x) * (y / gcd(x, y)); }
	long lcm(long x, long y) { return x * (y / gcd(x, y)); }

	class FS {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens()) {
				try { st = new StringTokenizer(br.readLine()); }
				catch (Exception e) {}
			} return st.nextToken();
		}
		int nextInt() { return Integer.parseInt(next()); }
		long nextLong() { return Long.parseLong(next()); }
		double nextDouble() { return Double.parseDouble(next()); }
	}
}
