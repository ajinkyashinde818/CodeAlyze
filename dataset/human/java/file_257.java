import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.List;
import java.util.StringTokenizer;
import java.util.stream.Collectors;
public class Main {
	public static void main(String[] args){
		FastScanner sc = new FastScanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		List<Long> list = Arrays.stream(sc.nextLine().split(" ",0)).map(Long::valueOf).collect(Collectors.toList());
		int count = 0;
		boolean hasZero = false;
		for (long i : list) {
			if (i == 0) {
				hasZero = true;
				break;
			} else if (i < 0) {
				count++;
			}
		}

		long out = list.stream().mapToLong(Math::abs).sum();
		if (! (hasZero || count%2 == 0) ) {
			long min = list.stream().mapToLong(Math::abs).min().getAsLong();
			out-= min*2;
		}

		System.out.println(out);
	}

}

class FastScanner {
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
