import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		char[] s = sc.next().toCharArray();
		ArrayList<String> front = new ArrayList<>();
		ArrayList<String> back = new ArrayList<>();
		front.add(String.valueOf(s[0]));
		for(int i = 1; i < s.length; i++) {
			back.add(String.valueOf(s[i]));
		}
		int q = sc.nextInt();
		int c = 0;
		for(int i = 0; i < q; i++) {
			int t = sc.nextInt();
			if(t == 1) {
				c++;
			}else {
				int f = sc.nextInt();
				String x = sc.next();
				if((f == 1 && c % 2 == 0)||(f == 2 && c % 2 != 0)) {
					front.add(x);
				}else {
					back.add(x);
				}
			}
		}
		
		if(c % 2 == 0) {
			for(int i = front.size()-1; i >= 0; i--) {
				System.out.print(front.get(i));
			}
			for(String str : back) {
				System.out.print(str);
			}
		}else {
			for(int i = back.size()-1; i >= 0; i--) {
				System.out.print(back.get(i));
			}
			for(String str : front) {
				System.out.print(str);
			}
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
