import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);

		String S = sc.nextLine();

		String dream = "dream";
		String erase = "erase";

		int count = 0;
		while (count != -1) {
			if (S.startsWith(dream, count)) {
				count += 5;
				if (S.startsWith("er", count)) {
					if(S.startsWith(erase, count)) {
						count += 5;
						if(S.startsWith("r", count)) {
							count++;
						}
					} else {
						count += 2;
					}
				}
			} else if (S.startsWith(erase, count)) {
				count += 5;
				if (S.startsWith("r", count)) {
					count++;
				}
			} else {
				count = -1;
			}

			if (count == S.length()) {
				break;
			}
		}


		if (count != -1 ) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}

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
