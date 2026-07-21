import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

/* spar5h */

public class Main implements Runnable{    
	
	static boolean nextPermutation(int[] a) {
		
		int p = -1;
		
		for(int i = a.length - 2; i >= 0; i--) {
			
			if(a[i] < a[i + 1]) {
				p = i; break;
			}
		}	
		
		if(p == -1)
			return false;
		
		int q = -1;
		
		for(int i = a.length - 1; i > p; i--) {
			
			if(a[i] > a[p]) {
				q = i; break;
			}
		}
		
		int temp = a[p]; a[p] = a[q]; a[q] = temp;
		
		for(int i = 0; i < (a.length - (p + 1)) / 2; i++) {
			temp = a[p + 1 + i]; a[p + 1 + i] = a[a.length - i - 1]; a[a.length - i - 1] = temp; 
		}
		
		return true;
	}
	
	public void run() {
		
		InputReader s = new InputReader(System.in);
		PrintWriter w = new PrintWriter(System.out);
		
		int n = s.nextInt();
		
		int[] a = new int[n];
		
		for(int i = 0; i < n; i++)
			a[i] = i + 1;
		
		int k = s.nextInt() / 100;
		
		int[] count = new int[n + 1];
		int[] bonus = new int[n + 1];
		
		for(int i = 1; i <= n; i++) {
			count[i] = s.nextInt(); bonus[i] = s.nextInt() / 100;
		}
		
		int minCount = Integer.MAX_VALUE;
		
		while(true) {
			
			int val = 0, pCount = 0;
			
			for(int i = 0; i < n; i++) {
			
				if(val + count[a[i]] * a[i] + bonus[a[i]] < k) {
					val += count[a[i]] * a[i] + bonus[a[i]]; pCount += count[a[i]]; continue;
				}
				
				int ans = count[a[i]];
				
				int l = 0, r = count[a[i]] - 1;
				
				while(l <= r) {
					
					int mid = (l + r) / 2;
					
					if(mid * a[i] >= k - val) {
						ans = mid; r = mid - 1;
					}
					else
						l = mid + 1;
				}
				
				pCount += ans;
				
				minCount = Math.min(minCount, pCount);
				
				break;
			}
			
			if(!nextPermutation(a))
				break;
		}
		
		w.println(minCount);
		
		w.close();
	}
	
	static class InputReader {
		
		private InputStream stream;
		private byte[] buf = new byte[1024];
		private int curChar;
		private int numChars;
		private SpaceCharFilter filter;
		
		public InputReader(InputStream stream)
		{
			this.stream = stream;
		}
		
		public int read()
		{
			if (numChars==-1) 
				throw new InputMismatchException();
			
			if (curChar >= numChars)
			{
				curChar = 0;
				try 
				{
					numChars = stream.read(buf);
				}
				catch (IOException e)
				{
					throw new InputMismatchException();
				}
				
				if(numChars <= 0)				
					return -1;
			}
			return buf[curChar++];
		}
	 
		public String nextLine()
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
		}
		public int nextInt()
		{
			int c = read();
			
			while(isSpaceChar(c)) 
				c = read();
			
			int sgn = 1;
			
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			
			int res = 0;
			do 
			{
				if(c<'0'||c>'9') 
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c)); 
			
			return res * sgn;
		}
		
		public long nextLong() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			long res = 0;
			
			do 
			{
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			while (!isSpaceChar(c));
				return res * sgn;
		}
		
		public double nextDouble() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') 
			{
				sgn = -1;
				c = read();
			}
			double res = 0;
			while (!isSpaceChar(c) && c != '.') 
			{
				if (c == 'e' || c == 'E')
					return res * Math.pow(10, nextInt());
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			}
			if (c == '.') 
			{
				c = read();
				double m = 1;
				while (!isSpaceChar(c)) 
				{
					if (c == 'e' || c == 'E')
						return res * Math.pow(10, nextInt());
					if (c < '0' || c > '9')
						throw new InputMismatchException();
					m /= 10;
					res += (c - '0') * m;
					c = read();
				}
			}
			return res * sgn;
		}
		
		public String readString() 
		{
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do 
			{
				res.appendCodePoint(c);
				c = read();
			} 
			while (!isSpaceChar(c));
			
			return res.toString();
		}
	 
		public boolean isSpaceChar(int c) 
		{
			if (filter != null)
				return filter.isSpaceChar(c);
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}
	 
		public String next() 
		{
			return readString();
		}
		
		public interface SpaceCharFilter 
		{
			public boolean isSpaceChar(int ch);
		}
	}
    
	public static void main(String args[]) throws Exception
	{
		new Thread(null, new Main(),"Main",1<<26).start();
	}
}
