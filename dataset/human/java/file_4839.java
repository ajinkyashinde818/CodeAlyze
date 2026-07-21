import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Solve solver = new Solve();
        solver.solve(1, in, out);
        out.close();
    }
    
    static class Solve {
    	public void solve(int testNumber, InputReader in, OutputWriter out) {
    		long n = in.nextLong();
			long N = 5;
			long ans = 0;
			if(n%2==0) {
				
	    		while(N<=n) {
	    			ans+=n/(N*2);
	    			N*=5;
	    		}
	    		out.println(ans);
			} else {
				out.println(0);
			}
    	}
    }
    
    static class OutputWriter {
	    private final PrintWriter writer;
	
	    public OutputWriter(OutputStream outputStream) {
	        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
	    }
	
	    public OutputWriter(Writer writer) {
	        this.writer = new PrintWriter(writer);
	    }
	
	    public void close() {
	        writer.close();
	    }
	
	    public void println(String string) {
	        writer.println(string);
	    }
	    
	    public void println(int number) {
	        writer.println(number);
	    }
	    
	    public void println(long number) {
	        writer.println(number);
	    }
	    
	    public void print(long number) {
	        writer.print(number);
	    }
	    
	    public void print(int number) {
	        writer.print(number);
	    }
	    
	    public void print(String string) {
	        writer.print(string);
	    }
	}
    
	static class InputReader { 
		private InputStream in;
		private byte[] buffer = new byte[1024];
		private int curbuf;
		private int lenbuf;
		
		public InputReader(InputStream in) {
			this.in = in;
			this.curbuf = this.lenbuf = 0;
		}
		
		public String nextLine() {
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (b!=10) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
		
		public boolean hasNextByte() {
			if (curbuf >= lenbuf) {
				curbuf = 0;
				try {
					lenbuf = in.read(buffer);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (lenbuf <= 0)
					return false;
			}
			return true;
		}
 
		private int readByte() {
			if (hasNextByte())
				return buffer[curbuf++];
			else
				return -1;
		}
 
		private boolean isSpaceChar(int c) {
			return !(c >= 33 && c <= 126);
		}
 
		private void skip() {
			while (hasNextByte() && isSpaceChar(buffer[curbuf]))
				curbuf++;
		}
 
		public boolean hasNext() {
			skip();
			return hasNextByte();
		}
 
		public String next() {
			if (!hasNext())
				throw new NoSuchElementException();
			StringBuilder sb = new StringBuilder();
			int b = readByte();
			while (!isSpaceChar(b)) {
				sb.appendCodePoint(b);
				b = readByte();
			}
			return sb.toString();
		}
 
		public int nextInt() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
 
		public long nextLong() {
			if (!hasNext())
				throw new NoSuchElementException();
			int c = readByte();
			while (isSpaceChar(c))
				c = readByte();
			boolean minus = false;
			if (c == '-') {
				minus = true;
				c = readByte();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res = res * 10 + c - '0';
				c = readByte();
			} while (!isSpaceChar(c));
			return (minus) ? -res : res;
		}
		
		public double nextDouble() {
			return Double.parseDouble(next());
		}
 
		public int[] nextIntArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}
 
		public long[] nextLongArray(int n) {
			long[] a = new long[n];
			for (int i = 0; i < n; i++)
				a[i] = nextLong();
			return a;
		}
 
		public char[][] nextCharMap(int n, int m) {
			char[][] map = new char[n][m];
			for (int i = 0; i < n; i++)
				map[i] = next().toCharArray();
			return map;
		}
	}
}
