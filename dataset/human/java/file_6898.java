import java.io.*;
import java.util.*;

import static java.lang.Math.*;

public class Main implements Comparable {
    @Override
    public int compareTo(Object s) {
        return 0;
    }

    static public class pair {
        int u;
        int idx;
        int val;

        public pair(int x, int i) {
            u = x;
            idx = i;
            val = -1;
        }
    }


    static ArrayList<Integer>[] adj;
    static Integer[] value, weight, Arr;
    static long inf = (long) 1e16;
    static int n, m;

    static boolean[][] matrix;
    static double[][] memo;
    static long mod = (long) (1e9 + 7);

    public static boolean sub(String a, String b) {
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == b.charAt(i) || a.charAt(i) == '?' || b.charAt(i) == '?')
                continue;
            return false;
        }
        return true;
    }

    public static boolean cont(String a, String b) {
        int n = b.length();
        for (int i = 0; i < a.length() - n; i++) {
            if (sub(a.substring(i, i + n), b))
                return true;
        }
        return false;
    }

    public static int inter(String a, String b) {
        int n = min(a.length(), b.length());
        if (cont(a, b) || cont(b, a))
            return n;
        while (n > 0) {
            if (sub(a.substring(a.length() - n), (b.substring(0, n))))
                return n;
            n--;
        }
        return 0;
    }

    static TreeSet<String> ts;

    public static void backtrack(int idx, int upperBound, String str) {
        if (idx == n) {
            ts.add(str);
            return;
        }
        for (int i = 0; i <= upperBound + 1; i++) {
            backtrack(idx + 1, Math.max(upperBound, i), str + (char) ('a' + i));
        }
    }

    static int w, maxvalue = 2;
    static double[] prob;
    static double mem[][][];
    static int[][][] memm;

    public static double dp(int one, int two, int three) {
        if (one == 0 && two == 0 && three == 0) return 0;
        if (mem[one][two][three] > -0.5) return mem[one][two][three];
        double ans = 0;
        double d = (n * 1d) / (one + two + three);
        int c = 0;
        if (three > 0) {
            ans += (d + dp(one, two + 1, three - 1));
            c++;
        }
        if (two > 0) {
            ans += (d + dp(one + 1, two - 1, three));
            c++;
        }
        if (one > 0) {
            ans += (d + dp(one - 1, two, three));
            c++;
        }
        return mem[one][two][three] = ans / c;
    }

    public static int count(int one, int two, int three) {
        if (one == 0 && two == 0 && three == 0) return 1;
        if (memm[one][two][three] != -1) return memm[one][two][three];
        int ans = 0;
        if (three > 0)
            ans += count(one, two + 1, three - 1);
        if (two > 0)
            ans += count(one + 1, two - 1, three);
        if (one > 0)
            ans += count(one - 1, two, three);
        return memm[one][two][three] = ans;
    }

    static PrintWriter pw;

    static int T = 1;
    static int[] dp, parent, tin, tout, level;

    public static void dfs(int u) {
        tin[u] = T++;
        for (int v : adj[u]) {
            if (tin[v] == 0) {
                level[v] = level[u] + 1;
                dfs(v);
                parent[v] = u;
            }
        }
        tout[u] = T++;
    }

    public static void main(String[] args) throws Exception {

        Scanner sc = new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int per = sc.nextInt();
        int n = sc.nextInt();
        int[] Arr = new int[n];
        for (int i = 0; i < n; i++) Arr[i] = sc.nextInt();
        int ans=Arr[0]+per-Arr[n-1];
        for (int i = 0; i < n-1; i++)
            ans=max(ans,Arr[i+1]-Arr[i]);
        pw.println(per-ans);

        pw.close();
    }

    public static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(String s) throws FileNotFoundException {
            br = new BufferedReader(new FileReader(s));

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
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException, IOException {
            return br.ready();
        }

    }
}
