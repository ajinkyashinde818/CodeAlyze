import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        int n = sc.nextInt();
        long [] a = new long[n];
        long sum = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextLong();
            sum += a[i];
        }
        long mod = ((long) n * (n + 1)) / 2;
        if (sum % mod != 0) {
            out.println("NO");
            out.close();
            return;
        }
        sum /= mod;
        long [] sol = new long[n];
        for (int i = 0; i < n - 1; i++) {
            long dif = a[i + 1] - a[i];
            if (sum - dif < 0 || (sum - dif) % n != 0) {
                sol[n - 1 - i] = -1;
                continue;
            }
            sol[n - 1 - i] = (sum - dif) / n;
        }
        for (int i = 0; i < n; i++) {
            if (sol[i] == -1) {
                out.println("NO");
                out.close();
                return;
            }
        }
        out.println("YES");
        out.close();
    }


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
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
