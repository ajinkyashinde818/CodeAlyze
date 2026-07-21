import java.io.*;
import java.util.StringTokenizer;

import java.util.Arrays;
public class Main {

    public static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(String s) {
            try {
                br = new BufferedReader(new FileReader(s));
            } catch (FileNotFoundException e) {
                // TODO Auto-generated catch block
                e.printStackTrace();
            }
        }

        public FastScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    // TODO Auto-generated catch block
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
        }
    }

    public static void main(String[] args) {
        FastScanner fs = new FastScanner();
        int N = fs.nextInt();
        long K = fs.nextLong();
        int[] A = new int[N];

        for (int i = 0;i < N; ++i) {
            A[i] = fs.nextInt() - 1;
        }


        boolean[] visited = new boolean[N];
        int[] lengths = new int[N];
        Pair p = dfs(0, lengths, visited, A);

        int lengthToStart = lengths[p.a];
        int cycleStart = p.a;
        int cycleLength = p.b;

//        System.out.println(lengthToStart);
//        System.out.println(cycleStart);
//        System.out.println(cycleLength);

        if (K > lengthToStart) {
            K -= lengthToStart;
            K = K % cycleLength;
            K += lengthToStart;
        }

        Arrays.fill(visited, false);
        System.out.println(traverse(K, A, visited, 0) + 1);

    }

    private static int traverse(long steps, int[] A, boolean[] visited, int start) {
        if (steps == 0) {
            return start;
        }

        if (visited[start]) {
            return -1;
        }

        visited[start] = true;
        return traverse(steps - 1, A, visited, A[start]);
    }

    private static Pair dfs(int start, int[] lengths, boolean[] visited, int[] a) {
        visited[start] = true;

        if (visited[a[start]]) {
            return new Pair(a[start], lengths[start] - lengths[a[start]] + 1);
        }

        lengths[a[start]] = lengths[start] + 1;

        return dfs(a[start], lengths, visited, a);
    }

    private static class Pair {
        int a;
        int b;

        public Pair(int a, int b) {
            this.a = a;
            this.b = b;
        }
    }
}
