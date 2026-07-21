import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        FastReader fs = new FastReader();
        final int inf = Integer.MAX_VALUE;
        int n = fs.nextInt();
        boolean ok = false;
        int cnt = 0;
        for (int i = 0; i < n; i ++) {
            int x = fs.nextInt();
            int y = fs.nextInt();
            if (x == y) cnt ++;
            else cnt = 0;
            if (cnt >= 3) ok = true;
        }
        if (!ok) System.out.println("No");
        else System.out.println("Yes");





    }


    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine() {
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }
    }
}
