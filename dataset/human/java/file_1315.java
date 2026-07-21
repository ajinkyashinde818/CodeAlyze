import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

/*
			  br = new BufferedReader(new FileReader("input.txt"));
			  pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
			  br = new BufferedReader(new InputStreamReader(System.in));
			  pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
 */

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int m = readInt();
			char[][] big = load(n);
			char[][] small = load(m);
			boolean can = false;
			for(int a = 0; a <= n-m; a++) {
				for(int b = 0; b <= n-m; b++) {
					int match = 0;
					for(int i = 0; i < m; i++) {
						for(int j = 0; j < m; j++) {
							if(big[a+i][b+j] == small[i][j]) {
								match++;
							}
						}
					}
					can |= match == m*m;
				}
			}
			pw.println(can ? "Yes" : "No");
		}
		exitImmediately();
	}

	public static char[][] load(int s) throws IOException {
		char[][] r = new char[s][s];
		for(int i = 0; i < s; i++) {
			String ss = readToken();
			for(int j = 0; j < s; j++) {
				r[i][j] = ss.charAt(j);
			}
		}
		return r;
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(readToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(readToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(readToken());
	}

	private static String readLine() throws IOException  {
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String readToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(readLine().trim());
		}
		return st.nextToken();
	}
}
