import java.util.*;
import java.io.*;

/*
3 3 10
60 2 2 4
70 8 7 9
50 2 3 9

120
 */
public class Main {
    public static void main(String[] args) throws IOException {
        int N = nextInt();
        int M = nextInt();
        int X = nextInt();

        int[][] graph = new int[N][M];
        int[] ack = new int[M];
        int[] cost = new int[N];
        int ans = inf;
        Boolean ok;

        // 入力
        for (int i = 0; i < N; i++) {
            cost[i] = nextInt();
            for (int j = 0; j < M; j++) {
                graph[i][j] = nextInt();
            }
        }

        // 処理
        for (int s = 0; s < (int) pow(2, N); s++) { // 1 << N
            fill(ack, 0);
            int cost_sum = 0;
            for (int i = 0; i < N; i++) { // 参考書
                if ((s >> i & 1) == 0) { // 買ってないなら何もしない
//                    System.out.println("(" + int2bin(s, N)
//                            + " " + int2bin((s >> i), N)
//                            + " " + int2bin((s >> i & 1), N)
//                            + ")");
                    continue;
                }
//                System.out.println(int2bin(s, N)
//                        + " " + int2bin((s >> i), N)
//                        + " " + int2bin((s >> i & 1), N)
//                );
                cost_sum += cost[i];
                for (int j = 0; j < M; j++) { // 経験値
                    ack[j] += graph[i][j];
                }
            }
            ok = true;
            for (int j = 0; j < M; j++) {
                if (ack[j] < X) {
                    ok = false;
                }
            }
            if (ok) {
                ans = min(ans, cost_sum);
            }
            System.out.println();
        }

        if (ans == inf) {
            ans = -1;
        }
        System.out.println(ans);
    }

    // constant
    static StringBuilder sb;
    static StringTokenizer st;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    static final int inf = Integer.MAX_VALUE / 2;
    static final long linf = Long.MAX_VALUE / 3;
    static final double dinf = Double.MAX_VALUE / 3;
    static final double eps = 1e-10;
    static final double pi = Math.PI;

    // pow
    static double pow(int x, int y) {
        return Math.pow(x, y);
    }

    // max min
    static int max(int x, int y) {
        return Math.max(x, y);
    }

    static int min(int x, int y) {
        return Math.min(x, y);
    }

    static int max(int x, int y, int z) {
        x = Math.max(x, y);
        x = Math.max(x, z);
        return x;
    }

    static int min(int x, int y, int z) {
        x = Math.min(x, y);
        x = Math.min(x, z);
        return x;
    }

    static long max(long x, long y) {
        return Math.max(x, y);
    }

    static long min(long x, long y) {
        return Math.min(x, y);
    }

    static long max(long x, long y, long z) {
        x = Math.max(x, y);
        x = Math.max(x, z);
        return x;
    }

    static long min(long x, long y, long z) {
        x = Math.min(x, y);
        x = Math.min(x, z);
        return x;
    }

    static double max(double x, double y) {
        return Math.max(x, y);
    }

    static double min(double x, double y) {
        return Math.min(x, y);
    }

    static double max(double x, double y, double z) {
        x = Math.max(x, y);
        x = Math.max(x, z);
        return x;
    }

    static double min(double x, double y, double z) {
        x = Math.min(x, y);
        x = Math.min(x, z);
        return x;
    }

    // sort
    static void sort(int[] ar) {
        Arrays.sort(ar);
    }

    static void sort(long[] ar) {
        Arrays.sort(ar);
    }

    static void sort(double[] ar) {
        Arrays.sort(ar);
    }

    static void sort(char[] ar) {
        Arrays.sort(ar);
    }

    static void rsort(int[] ar) {
        Arrays.sort(ar);
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            int tmp = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = tmp;
        }
    }

    static void rsort(long[] ar) {
        Arrays.sort(ar);
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            long tmp = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = tmp;
        }
    }

    static void rsort(double[] ar) {
        Arrays.sort(ar);
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            double tmp = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = tmp;
        }
    }

    static void rsort(char[] ar) {
        Arrays.sort(ar);
        int len = ar.length;
        for (int i = 0; i < len / 2; i++) {
            char tmp = ar[i];
            ar[i] = ar[len - 1 - i];
            ar[len - 1 - i] = tmp;
        }
    }

    // initialize
    static void fill(int arr[], int x) {
        Arrays.fill(arr, x);
    }

    static void fill(long arr[], long x) {
        Arrays.fill(arr, x);
    }

    static void fill(boolean arr[], boolean x) {
        Arrays.fill(arr, x);
    }

    static void fill(double arr[], double x) {
        Arrays.fill(arr, x);
    }

    static void fill(int arr[][], int x) {
        for (int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], x);
        }
    }

    static void fill(long arr[][], long x) {
        for (int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], x);
        }
    }

    static void fill(double arr[][], double x) {
        for (int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], x);
        }
    }

    static void fill(boolean arr[][], boolean x) {
        for (int i = 0; i < arr.length; i++) {
            Arrays.fill(arr[i], x);
        }
    }

    // scanner
    static char nextChar() throws IOException {
        return next().charAt(0);
    }

    static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }

    static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static int[] readArray(int n) throws IOException {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextInt();
        }
        return a;
    }

    static long[] readLongArray(int n) throws IOException {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nextLong();
        }
        return a;
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens()) {
            st = new StringTokenizer(br.readLine().trim());
        }
        return st.nextToken();
    }

    // cast
    static String padLeftZeros(String inputString, int length) {
        if (inputString.length() >= length) {
            return inputString;
        }
        sb = new StringBuilder();
        while (sb.length() < length - inputString.length()) {
            sb.append('0');
        }
        sb.append(inputString);

        return sb.toString();
    }

    static String int2bin(int num, int length) {
        return padLeftZeros(Integer.toBinaryString(num), length);
    }

    static int char2int(Character c) {
        return Character.getNumericValue(c);
    }

    static double char2double(Character c) {
        return (double) char2int(c);
    }

    // nCr
    static int nCr(int n, int r) {
        return fact(n) / (fact(r) * fact(n - r));
    }

    static int fact(int n) {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res = res * i;
        }
        return res;
    }

    // gcd
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            a = a % b; // 残り部分
            return gcd(b, a); // 残り部分から最小の正方形を見つける
        }
    }
}
