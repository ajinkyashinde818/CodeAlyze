import java.io.*;
import java.util.*;

public class Main {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);

	public static void main(String[] args) {
		int n= in.nextInt();
		boolean isok = false;
		int counter = 0;
		for (int i = 0; i < n; i++) {
			int a = in.nextInt();
			int b = in.nextInt();
			if(a != b) {
				isok = false;
				counter = 0;
				continue;
			}
			isok = true;
			counter++;
			if(counter == 3) {
				break;
			}
		}
		
        if(isok && counter == 3) {
			out.println("Yes");
		} else {
			out.println("No");
		}
		out.close();
	}
	
	static void update(int[][] dp0, int[][] dp, int i, int j) {
		//(i-1, j-1), (i-1, j), (i-1, j+1)
		//(i, j-1), (i, j), (i, j+1)
		//(i+1, j-1), (i+1, j), (i+1, j+1)

		//(i-1 or j-1) should not be lesser than 0
		//(i+1 or j+1) should not be greater than 2

		//difference between (i or j) and its inc or dec should not cross 2

		for (int k = i-1; k <= i+1; k++) {
			for (int k2 = j-1; k2 <= j+1; k2++) {
				
				if(k >= 0 && k <= 2 && k2 >= 0 && k2 <= 2) {
					//valid
					if(dp0[k][k2] == 1) {
						dp[k][k2] = toggle(dp[k][k2]);
					}
					if(k2 == j+1) {
						// out.println("("+k+","+k2+")=>"+dp[k][k2]);
						dp[k][k2] = toggle(dp[k][k2]);
					} else {
						// out.print("("+k+","+k2+")=>"+dp[k][k2]+",");
						dp[k][k2]= toggle(dp[k][k2]);
					}
				}
			}
		}

// 		(I, j-1), (I, j+1), const I , change in j
// (I+1, j-1), (I+1, j+1), change 1 (+ve), change in j
// (I-1, j-1), (I-1, j+1), change 1 (-ve), change in j
// (I-1, j), (I+1, j)  change in I, const j

	}

	static int toggle(int n) {
		if(n%2==0) {
			return 1;
		} else {
			return 0;
		}
	}
	
	static int [][] Grid(int m, int n) {
		int [][]dp = new int[m][n];
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				dp[i][j] = in.nextInt();
			}
		}
		return dp;
	}

	public static long powmod(int x, long y, long mod) {
        long total = 1;
        for (long i = 0; i < y; i++) {
            total = (total * x) % mod;
        }
        return total;
 
    }
    

    static class Pair {
        int first = 1;
        int second = 2;
    }

    public void fibonacci(int N) {
        boolean arr[] = new boolean[N];
        Arrays.fill(arr, false);
        arr[0] = true;
        if(N>1)
            arr[1] = true;

        Pair p = new Pair();
        for (int i = 3; i <= N; i++) {
            
            if(p.first + p.second == i) {
                arr[i-1] = true;
                p.first = p.second;
                p.second = i;
            } else {
                arr[i-1] = false;
            }
        }
    }

    public class Solver {
		Solver() {
			
        }
        
    }

    static long factorial(long x) {
        if(x <= 1) {
            return 1;
        }
        long res = 2;
        for (int i = 3; i <= x; i++) {
            res = res * i;
        }
        return res;
    }
    
    static long gcdOfFactorial(long a, long b) { 
        if (b == 0) 
            return a; 
        return gcdOfFactorial(b, a % b);
    } 
	
	static class StdIn {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public StdIn(InputStream in) {
			try{
				din = new DataInputStream(in);
			} catch(Exception e) {
				throw new RuntimeException();
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String next() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c=read();
			}
			return s.toString();
		}
		public String nextLine() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c = read();
			}
			return s.toString();
		}
		public int nextInt() {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		public int[] readIntArray(int n, int os) {
			int[] ar = new int[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextInt()+os;
			return ar;
		}
		public long nextLong() {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public long[] readLongArray(int n, long os) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong()+os;
			return ar;
		}
		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() {
			try{
				if (bufferPointer == bytesRead)
					fillBuffer();
				return buffer[bufferPointer++];
			} catch(IOException e) {
				throw new RuntimeException();
			}
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}
