import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public final class Main {

	public static void main(String[] args) {
		final FastScanner fs = new FastScanner();
		final int time = fs.nextInt();
		int sameTime = 0;

		for (int i = 0; i < time; i++) {
			int a = fs.nextInt();
			int b = fs.nextInt();
			//System.out.println("a=" + a + "b=" + b);
			if (a == b) {
				sameTime++;
				if (sameTime >= 3) {
					System.out.println("Yes");
					System.exit(0);
				}

			} else {
				sameTime = 0;
			}
		}
		System.out.println("No");
	}

    static class FastScanner {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer("");

        String next() {
            while (!st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    //noinspection CallToPrintStackTrace
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] readArray(int n) {
            final int[] a = new int[n];
            for (int i = 0; i < n; i++) { a[i] = nextInt(); }
            return a;
        }

        long nextLong() {
            return Long.parseLong(next());
        }
    }
}
