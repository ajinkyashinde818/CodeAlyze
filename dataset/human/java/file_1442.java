import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        FastScannerB fs = new FastScannerB();
        PrintWriter out = new PrintWriter(System.out);

        int n = fs.nextInt(), m = fs.nextInt();
        char[][] a = new char[n][n];
        for(int i = 0; i < n; i++) a[i] = fs.nextCharArray();
        char[][] b = new char[m][m];
        for(int i = 0; i < m; i++) b[i] = fs.nextCharArray();
        StringBuilder bCode = new StringBuilder();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < m; j++) {
                bCode.append(b[i][j] == '#' ? 1 : 0);
            }
        }
        boolean good = false;
        all:
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i + m <= n && j + m <= n) {
                    String abc = getCode(a, i, j, m);
                    if(abc.equals(bCode.toString())) {
                        good = true;
                        break all;
                    }
                }
            }
        }
        out.println(good ? "Yes" : "No");

        out.close();
    }

    static String getCode(char[][] a, int i, int j, int m) {
        StringBuilder res = new StringBuilder();
        int lim = i+m, limj = j + m;
        for(int k = i; k < lim; k++) {
            for(int l = j; l < limj; l++) {
                res.append(a[k][l] == '#' ? 1 : 0);
            }
        }
        return res.toString();
    }
}


class FastScannerB {
    BufferedReader br;
    StringTokenizer st;

    public FastScannerB() {
        try {
            br = new BufferedReader(new InputStreamReader(System.in));
            st = new StringTokenizer("");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public String next() {
        if (st.hasMoreTokens()) return st.nextToken();
        try {
            st = new StringTokenizer(br.readLine());
        } catch (Exception e) {
            e.printStackTrace();
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String line = "";
        try {
            line = br.readLine();
        } catch (Exception e) {
            e.printStackTrace();
        }
        return line;
    }

    public Integer[] nextIntegerArray(int n) {
        Integer[] a = new Integer[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) a[i] = nextInt();
        return a;
    }

    public char[] nextCharArray() {
        return next().toCharArray();
    }
}
