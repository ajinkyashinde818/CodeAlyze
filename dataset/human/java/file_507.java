import java.util.*;

import static java.lang.Math.*;

import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;

public class Main {

	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(System.out);
		int n = sc.nextInt();
		int r = sc.nextInt();
		if(n>=10) {
			pw.println(r);
		}else {
			pw.println(r+100*(10-n));
		}
		pw.close();

	}
	static class Scanner 
	{
		StringTokenizer st;
		BufferedReader br;

		public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

		public String next() throws IOException 
		{
			while (st == null || !st.hasMoreTokens()) 
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		public int nextInt() throws IOException {return Integer.parseInt(next());}
		
		public long nextLong() throws IOException {return Long.parseLong(next());}

		public String nextLine() throws IOException {return br.readLine();}
		
		public double nextDouble() throws IOException
		{
			String x = next();
			StringBuilder sb = new StringBuilder("0");
			double res = 0, f = 1;
			boolean dec = false, neg = false;
			int start = 0;
			if(x.charAt(0) == '-')
			{
				neg = true;
				start++;
			}
			for(int i = start; i < x.length(); i++)
				if(x.charAt(i) == '.')
				{
					res = Long.parseLong(sb.toString());
					sb = new StringBuilder("0");
					dec = true;
				}
				else
				{
					sb.append(x.charAt(i));
					if(dec)
						f *= 10;
				}
			res += Long.parseLong(sb.toString()) / f;
			return res * (neg?-1:1);
		}
		
		public boolean ready() throws IOException {return br.ready();}


	}
	static class pair implements Comparable<pair> {
		int x;
		int y;

		public pair(int d, int u) {
			x = d;
			y = u;
		}

		@Override
		public int compareTo(pair o) {
			// TODO Auto-generated method stub
			return y - o.y;
		}

	}

	static class pair2 implements Comparable<pair2> {
		long x;
		int y;

		@Override
		public String toString() {
			// TODO Auto-generated method stub
			return y + " ";
		}

		public pair2(long d, int u) {
			x = d;
			y = u;
		}

		@Override
		public int compareTo(pair2 o) {
			// TODO Auto-generated method stub
			if (x - o.x > 0)
				return 1;
			else if (x - o.x == 0)
				return 0;
			return -1;
		}

	}

}
