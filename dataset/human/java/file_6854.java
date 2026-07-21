import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        FastScanner s = new FastScanner(System.in);
        PrintWriter out = new PrintWriter(System.out);
        
        long k, n, a0, ai, aj;
        long dist = -1;
        k = s.nextLong();
        n = s.nextLong();
        a0 = s.nextLong();
        aj = s.nextLong();
        dist = Math.max(dist, aj-a0);

        ai = aj;

        for (long i = 2; i < n; i++) {
            aj = s.nextLong();
            dist = Math.max(dist, aj-ai);
            ai = aj;
        }
        dist = Math.max(dist, k - (aj-a0));

        out.println(k - dist);

        out.close();
    }

    static class FastScanner {
		
		BufferedReader br; StringTokenizer st;
		FastScanner(InputStream is) {
			br = new BufferedReader(new InputStreamReader(is));
			st = new StringTokenizer("");
		}
		String next() {
			while(!st.hasMoreElements()) {
				try { st = new StringTokenizer(br.readLine()); }
				catch(Exception e) {}
			}
			return st.nextToken();
		}
		
        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() {return Long.parseLong(next()); }
		
	}
}
