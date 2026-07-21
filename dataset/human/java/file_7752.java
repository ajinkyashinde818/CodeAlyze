import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		FastScanner sc = new FastScanner(System.in);
		long n = sc.nextLong(), k = sc.nextLong();
		long[] end = new long[(int)n];
		for(int i = 0; i < n; i++) {
			end[i] = sc.nextLong();
		}
		Map<Long, Long> map = new HashMap<>();
		boolean check = false;
		long next = 1l;
		long count = 0l;
		long st = 0l;
		long en = 0l;
		List<Long> list = new ArrayList<>();
		List<Long> listn = new ArrayList<>();
		while(!check) {
			if(map.containsKey(next)) {
				st = (long)map.get(next);//count
				en = (long)map.size();//count
				List<Long> lista = new ArrayList<>(map.keySet());
				List<Long> listb = new ArrayList<>(map.values());
				list = lista;
				listn = listb;
				break;
			}else {
				map.put(next, count);
				next = end[(int)next -1];
				count++;
			}
		}
		long t = 0l;
		if(st != 0) {
			t = k- st + 1;
		}else {
			t = k+1;
		}
		long an = t%(en-st);
		int index = 0;
		if(st > k) {
			index = listn.indexOf(k);
		}else if(an == 0) {
			index = listn.indexOf(en -1);
		}else {
			index = listn.indexOf(st + an -1);
		}
		System.out.println(list.get(index));

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
