import java.io.*;
import java.io.IOException;
import java.util.*;

class Main {
    final static int INF = 1 << 28;
    final static long LNF = 1L << 60;
    final static double EPS = 1e-9;
    final static double GOLDEN_RATIO = (1.0 + Math.sqrt(5)) / 2.0;

    static final long MOD = 1_000_000_007;

    public static void main(String[] args) throws Exception {
        final MyScanner sc = new MyScanner();
        long N;
        N = sc.nextLong();
        long K;
        K = sc.nextLong();
        long L;
        L = sc.nextLong();
        long[] p = new long[(int) (K)];
        long[] q = new long[(int) (K)];
        for (int i = 0; i < K; i++) {
            p[i] = sc.nextLong();
            q[i] = sc.nextLong();
        }
        long[] r = new long[(int) (L)];
        long[] s = new long[(int) (L)];
        for (int i = 0; i < L; i++) {
            r[i] = sc.nextLong();
            s[i] = sc.nextLong();
        }
        solve(N, K, L, p, q, r, s);
    }

    static void solve(long N, long K, long L, long[] p, long[] q, long[] r, long[] s) {
        UnionFind kuf = new UnionFind((int)N);
        UnionFind luf = new UnionFind((int)N);

        for (int i = 0; i < K; i++){
            p[i]--; q[i]--;
        }
        for (int i = 0; i < L; i++){
            r[i]--; s[i]--;
        }

        for (int i = 0; i < K; i++) {
            kuf.union((int)p[i], (int)q[i]);
        }
        for (int i = 0; i < L; i++) {
            luf.union((int)r[i], (int)s[i]);
        }
        StringBuffer sb = new StringBuffer();
        HashMap<ArrayList, Integer> hm = new HashMap<>();
        
        for (int i = 0; i < N; i++) {
            ArrayList al = new ArrayList<>();
            al.add(kuf.find(i));
            al.add(luf.find(i));
            if(!hm.containsKey(al)) hm.put(al, 1);
            else hm.put(al, hm.get(al)+1);
        }
        for (int i = 0; i < N; i++) {
            ArrayList al = new ArrayList<>();
            al.add(kuf.find(i));
            al.add(luf.find(i));
            sb.append(hm.get(al));
            sb.append(" ");
        }

        System.out.println(new String(sb));
    }

    static public class UnionFind {
        int[] parents;
        int[] rank;
    
        public UnionFind(int n) {
            parents = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parents[i] = i;
                rank[i] = 0;
            }
        }
    
        public int find(int i) {
            return root(i);
        }
    
        public boolean isSameSet(int i, int j) {
            return this.find(i) == this.find(j);
        }
    
        public void union(int i, int j) {
            int ri = root(i);
            int rj = root(j);
            if(ri == rj) return;
            else {
                if(rank[ri] < rank[rj]) parents[ri] = rj;
                else parents[rj] = ri;
                // Increment rank of root(i);
                if(rank[ri] == rank[rj]) rank[ri]++;
            }
        }
    
        private int root(int n) {
            if (parents[n] == n) {
                return n;
            } else {
                // Path compresseion.
                parents[n] = root(parents[n]);
                return parents[n];
            }
        }
    }

    static class MyScanner {

        BufferedReader br;
        StringTokenizer st;

        MyScanner(FileReader fileReader) {
            br = new BufferedReader(fileReader);
        }

        MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nn() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String next() {
            String ans = "";
            try {
                ans = br.readLine();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
            return ans;
        }

        char nextChar() {
            return nn().charAt(0);
        }

        int nextInt() {
            return Integer.parseInt(nn());
        }

        long nextLong() {
            return Long.parseLong(nn());
        }

        double nextDouble() {
            return Double.parseDouble(nn());
        }

        Integer[] niArr0(int n) {
            Integer[] ar = new Integer[n];
            for (int i = 0; i < n; i++) {
                ar[i] = nextInt();
            }
            return ar;
        }

        Integer[] niArr1(int n) {
            Integer[] ar = new Integer[n + 1];
            for (int i = 1; i <= n; i++) {
                ar[i] = nextInt();
            }
            return ar;
        }

        Long[] nlArr0(int n) {
            Long[] ar = new Long[n];
            for (int i = 0; i < n; i++) {
                ar[i] = nextLong();
            }
            return ar;
        }

        Long[] nlArr1(int n) {
            Long[] ar = new Long[n + 1];
            for (int i = 1; i <= n; i++) {
                ar[i] = nextLong();
            }
            return ar;
        }
    }

}
