//package com.company;
// Always comment out package when submitting.
import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    public static class Task {
        public double dist(int[][] circles, int i1, int i2) {
            long xDiff = circles[i1][0] - circles[i2][0];
            long yDiff = circles[i1][1] - circles[i2][1];
            double diff = Math.sqrt(xDiff * xDiff + yDiff * yDiff);
            return Math.max(0 ,diff - circles[i1][2] - circles[i2][2]);
        }
        class Pair {
            int i; double d;

            public Pair(int i, double d) {
                this.i = i;
                this.d = d;
            }
        }
        public double shortestPath(int[][] circles, int is, int it) {
            int n = circles.length;
            double[] distance = new double[n];
            boolean[] visit = new boolean[n];
            Arrays.fill(distance, Long.MAX_VALUE);
            distance[is] = 0;
            visit[is] = true;
            PriorityQueue<Pair> edges = new PriorityQueue<>(new Comparator<Pair>() {
                @Override
                public int compare(Pair o1, Pair o2) {
                    return Double.compare(o1.d, o2.d);
                }
            });
            for (int i = 0; i < n; i++) if (!visit[i]) {
                edges.add(new Pair(i, distance[is] + dist(circles, is, i)));
            }
            while (!edges.isEmpty()) {
                Pair edge = edges.poll();
                if (visit[edge.i]) continue;
                visit[edge.i] = true;
                distance[edge.i] = edge.d;
                if (edge.i == it) return edge.d;
                for (int i = 0; i < n; i++) if (!visit[i]) {
                    edges.add(new Pair(i, distance[edge.i] + dist(circles, edge.i, i)));
                }
            }
            throw new RuntimeException();
        }

        public void solve(Scanner sc, PrintWriter pw) throws IOException {
            int xStart = sc.nextInt();
            int yStart = sc.nextInt();
            int xEnd = sc.nextInt();
            int yEnd = sc.nextInt();
            int N = sc.nextInt();
            int[][] circles = new int[N + 2][3];
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < 3; j++) {
                    circles[i][j] = sc.nextInt();
                }
            }
            circles[N] = new int[]{xStart, yStart, 0};
            circles[N + 1] = new int[]{xEnd, yEnd, 0};
            pw.println(shortestPath(circles, N, N + 1));
        }
    }

    // template, actual code is in class Task.
    static long TIME_START, TIME_END;

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
//        Scanner sc = new Scanner(new FileInputStream("Test.in"));
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));
//        PrintWriter pw = new PrintWriter(new FileOutputStream("Test.out"));

        Runtime runtime = Runtime.getRuntime();
        long usedMemoryBefore = runtime.totalMemory() - runtime.freeMemory();
        TIME_START = System.currentTimeMillis();
        Task t = new Task();
        t.solve(sc, pw);
        TIME_END = System.currentTimeMillis();
        long usedMemoryAfter = runtime.totalMemory() - runtime.freeMemory();
        pw.close();
//        System.err.println("Memory increased: " + (usedMemoryAfter - usedMemoryBefore) / 1000000);
//        System.err.println("Time used: " + (TIME_END - TIME_START) + ".");
    }

    // Faster IO with BufferedReader wrapped with Scanner
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
