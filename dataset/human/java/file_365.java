import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;
import java.util.NoSuchElementException;
import java.util.TreeSet;


public class Main {
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();

    double sx = sc.nextLong();
    double sy = sc.nextLong();
    double tx = sc.nextLong();
    double ty = sc.nextLong();
    int N = sc.nextInt();


    double[] x = new double[N + 2];
    double[] y = new double[N + 2];
    double[] r = new double[N + 2];
    x[0] = sx;
    y[0] = sy;
    x[N + 1] = tx;
    y[N + 1] = ty;

    for (int i = 1; i <= N; i ++) {
      x[i] = sc.nextLong();
      y[i] = sc.nextLong();
      r[i] = sc.nextLong();
    }
    
    int[][] g = new int[N + 2][N + 1];
    double[][] w = new double[N + 2][N + 1];
    for (int i = 0; i < N + 2; i ++) {
      int ptr = 0;
      for (int j = 0; j < N + 2; j ++) {
        if (j != i) {
          g[i][ptr] = j;
          
          double dx = x[i] - x[j];
          double dy = y[i] - y[j];
          double len = Math.sqrt(dx * dx + dy * dy);
          w[i][ptr] = Math.max(0, len - r[i] - r[j]);
          ptr ++;
        }
      }
    }
    

    double[] ret = dijk(g, w, 0);
    System.out.println(ret[N + 1]);
    
  }
  
  public static double[] dijk(int[][] g, double[][] wg, int from)
  {
      int n = g.length;
      final double[] td = new double[n];
      Arrays.fill(td, Double.MAX_VALUE);
      TreeSet<Integer> q = new TreeSet<Integer>(new Comparator<Integer>(){
          public int compare(Integer a, Integer b) {
              if(td[a] - td[b] != 0)return Double.compare(td[a], td[b]);
              return a - b;
          }
      });
      q.add(from);
      td[from] = 0;
      
      while(q.size() > 0){
          int cur = q.pollFirst();
          
          for(int i = 0;i < g[cur].length;i++){
              int next = g[cur][i];
              double nd = td[cur] + wg[cur][i];
              if(nd < td[next]){
                  q.remove(next);
                  td[next] = nd;
                  q.add(next);
              }
          }
      }
      
      return td;
  }
}



class FastScanner {
	public static String debug = null;

	private final InputStream in = System.in;
	private int ptr = 0;
	private int buflen = 0;
	private byte[] buffer = new byte[1024];
	private boolean eos = false;

	private boolean hasNextByte() {
		if (ptr < buflen) {
			return true;
		} else {
			ptr = 0;
			try {
				if (debug != null) {
					buflen = debug.length();
					buffer = debug.getBytes();
					debug = "";
					eos = true;
				} else {
					buflen = in.read(buffer);
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			if (buflen < 0) {
				eos = true;
				return false;
			} else if (buflen == 0) {
				return false;
			}
		}
		return true;
	}

	private int readByte() {
		if (hasNextByte())
			return buffer[ptr++];
		else
			return -1;
	}

	private static boolean isPrintableChar(int c) {
		return 33 <= c && c <= 126;
	}

	private void skipUnprintable() {
		while (hasNextByte() && !isPrintableChar(buffer[ptr]))
			ptr++;
	}

	public boolean isEOS() {
		return this.eos;
	}

	public boolean hasNext() {
		skipUnprintable();
		return hasNextByte();
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = readByte();
		while (isPrintableChar(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
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

	public long[] nextLongList(int n) {
		return nextLongTable(1, n)[0];
	}

	public int[] nextIntList(int n) {
		return nextIntTable(1, n)[0];
	}

	public long[][] nextLongTable(int n, int m) {
		long[][] ret = new long[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextLong();
			}
		}
		return ret;
	}

	public int[][] nextIntTable(int n, int m) {
		int[][] ret = new int[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ret[i][j] = nextInt();
			}
		}
		return ret;
	}
}
