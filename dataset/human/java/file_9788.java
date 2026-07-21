import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		int n = sc.nextInt(), m = sc.nextInt(), x = sc.nextInt();
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		int[][] b = bi(n);
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i < (int)Math.pow(2, n); i++) {
			int[] buy = b[i];
			int[] total = new int[m];
			int money = 0;
			for(int j = 0; j < n; j++) {
				money += buy[j] * c[j];
				for(int k = 0; k < m; k++) {
					total[k] += (int) (buy[j] * a[j][k]);
				}
			}
			boolean check = true;
			for(int j = 0; j < m; j++) {
				if(total[j] < x) {
					check = false;
					break;
				}
			}
			if(check && ans > money) {
				ans = money;
			}
		}
		if(ans == Integer.MAX_VALUE) {
			ans = -1;
		}
			
		System.out.println(ans);
	}
	
	static int[][] bi(int n) {
		int all = (int)Math.pow(2, n);
		int[][] a = new int[all][n];
		for(int i = 0; i < all; i++) {
			Arrays.fill(a[i], 0);
			int x = 0;
			int num = i;
			while(num >= 2) {
				a[i][x] = num%2;
				x++;
				num /= 2;
			}
			a[i][x] = num;
		}
		return a;
	}
	
	static class FastScanner {
		private BufferedReader reader = null;
	    private StringTokenizer tokenizer = null;
	    public FastScanner(InputStream in) {
	        reader = new BufferedReader(new InputStreamReader(in));
	        tokenizer = null;
	    }

	    public String next() {
	        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                tokenizer = new StringTokenizer(reader.readLine());
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }
	        return tokenizer.nextToken();
	    }

	    public String nextLine() {
	        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
	            try {
	                return reader.readLine();
	            } catch (IOException e) {
	                throw new RuntimeException(e);
	            }
	        }

	        return tokenizer.nextToken("\n");
	    }

	    public long nextLong() {
	        return Long.parseLong(next());
	    }

	    public int nextInt() {
	        return Integer.parseInt(next());
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
	}
}
