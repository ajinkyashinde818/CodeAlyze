import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;


public class Main{
	static FastScanner sc = new FastScanner();
	static PrintWriter out = new PrintWriter(System.out);
	//static PriorityQueue <Integer> q ;
	//static Deque <Integer> q;
	//Deque deque = new LinkedList();
	//static HashMap <Integer, Integer> map;
	static int n;
	static String s;
	//static final int mod = 1_000_000_007;
	//static int H;
	//static int W;
	//static final int[] dx = {0,1,0,-1};
	//static final int[] dy = {-1,0,1,0};
	//static int max_d;
	//static int [][] S;				
	
	public static void main(String[] args) {
		n = sc.nextInt();
		long k = sc.nextLong();
		int a [] = sc.nextIntArray(n,  true);
		
		if (k<=200000) {
			int cur = 1;
			for (int j=0; j<k; j++) {
				int next = a[cur];
				cur = next;
			}
			out.println(cur);
		}
		
		else {
			boolean seen [] = new boolean [n+1];
			int i = 1;
			long count = 0;
			boolean ok = false;
			
			while (!seen[i]) {
				if (count==k) {
					ok = true;
					break;
				}
				
				seen[i] = true;
				int next = a[i];
				i = next;
				count++;
				
				if (seen[i])
					break;
			}
			
			if (ok)
				out.println(i);
			
			else {
				int cur = i;
				boolean check [] = new boolean [n+1];
				int c = 0;
				
				while (!check[cur]) {
					check[cur] = true;
					int next = a[cur];
					c++;
					cur = next;
				}
				
				k-=(count-c);		
				k%=c;
				
				cur = 1;
				for (int j=0; j<count+1-c+k-1; j++) {
					int next = a[cur];
					cur = next;
				}
			
				out.println(cur);
			}
		
		}
		
		out.flush();
	}
	
	
	

	
	static class FastScanner {
	    private final InputStream in = System.in;
	    private final byte[] buffer = new byte[1024];
	    private int ptr = 0;
	    private int buflen = 0;

	    private boolean hasNextByte() {
	      if (ptr < buflen) {
	        return true;
	      } else {
	        ptr = 0;
	        try {
	          buflen = in.read(buffer);
	        } catch (IOException e) {
	          e.printStackTrace();
	        }
	        if (buflen <= 0) {
	          return false;
	        }
	      }
	      return true;
	    }

	    private int readByte() {
	      if (hasNextByte()) return buffer[ptr++];
	      else return -1;
	    }

	    private static boolean isPrintableChar(int c) {
	      return 33 <= c && c <= 126;
	    }

	    private void skipUnprintable() {
	      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
	    }

	    public boolean hasNext() {
	      skipUnprintable();
	      return hasNextByte();
	    }

	    public String next() {
	      if (!hasNext()) throw new NoSuchElementException();
	      StringBuilder sb = new StringBuilder();
	      int b = readByte();
	      while (isPrintableChar(b)) {
	        sb.appendCodePoint(b);
	        b = readByte();
	      }
	      return sb.toString();
	    }
	    
	    public double nextDouble () {
	    	return Double.parseDouble(next());
	    }

	    public long nextLong() {
	      if (!hasNext()) throw new NoSuchElementException();
	      long n = 0;
	      boolean minus = false;
	      int b = readByte();
	      if (b == '-') {
	        minus = true;
	        b = readByte();
	      }
	      if (b < '0' || '9' < b) {
	        throw new NumberFormatException();
	      }
	      while (true) {
	        if ('0' <= b && b <= '9') {
	          n *= 10;
	          n += b - '0';
	        } else if (b == -1 || !isPrintableChar(b)) {
	          return minus ? -n : n;
	        } else {
	          throw new NumberFormatException();
	        }
	        b = readByte();
	      }
	    }

	    public int nextInt() {
	      return (int) nextLong();
	    }

	    public int[] nextIntArray(int N, boolean oneBased) {
	      if (oneBased) {
	        int[] array = new int[N + 1];
	        for (int i = 1; i <= N; i++) {
	          array[i] = sc.nextInt();
	        }
	        return array;
	      } else {
	        int[] array = new int[N];
	        for (int i = 0; i < N; i++) {
	          array[i] = sc.nextInt();
	        }
	        return array;
	      }
	    }

	    public long[] nextLongArray(int N, boolean oneBased) {
	      if (oneBased) {
	        long[] array = new long[N + 1];
	        for (int i = 1; i <= N; i++) {
	          array[i] = sc.nextLong();
	        }
	        return array;
	      } else {
	        long[] array = new long[N];
	        for (int i = 0; i < N; i++) {
	          array[i] = sc.nextLong();
	        }
	        return array;
	      }
	    }
	  }
}
