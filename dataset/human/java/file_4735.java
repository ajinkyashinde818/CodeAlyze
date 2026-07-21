import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        MyScanner sc = new MyScanner();
        PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
        String s = sc.next(); int n = s.length();
        int [] a = new int [n];
        for (int i = 0; i < n; i++) a[n - 1 - i] = s.charAt(i) - '0';
        int ans = 0; boolean carry = false;
        for (int i = 0; i < n; i++) {
            int look = a[i]; boolean special = false;
            if (carry) {
                look = (look + 1) % 10;
                if (look == 0) special = true;
            }
            if (look <= 4) {
                ans += look;
                carry = false;
                if (special) carry = true;
            } else if (look >= 6) {
                ans += (10 - look);
                carry = true;
            } else {
                ans += 5;
                if (i == n - 1 || a[i + 1] <= 4) carry = false;
                else carry = true;
            }
        }
        if (carry) ans += 1;
        out.println(ans);
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
