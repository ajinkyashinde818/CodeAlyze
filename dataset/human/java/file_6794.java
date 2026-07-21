import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
        TIME_START = System.currentTimeMillis();
        solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        pw.close();
        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");

    }

    static void solve(Scanner sc, PrintWriter pw) throws IOException {
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++)
            a[i] = sc.nextInt();

        // 5 10 15
        // 20-15 + 5 , 5 , 5
        // 0 5 15
        // 20-15 + 0 5 10

        int[] diff = new int[n];
        diff[0] = k - a[n - 1] + a[0];
        for (int i = 1; i < n; i++)
            diff[i] = a[i] - a[i - 1];

        Arrays.sort(diff);
        int sum = 0;
        for (int i = 0; i < n - 1; i++)
            sum += diff[i];

        pw.println(sum);

    }

    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader s) throws FileNotFoundException {
            br = new BufferedReader(s);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }

}
