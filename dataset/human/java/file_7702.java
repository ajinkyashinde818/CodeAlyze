import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Map.Entry;
import java.util.PriorityQueue;
import java.util.Scanner;
import java.util.StringTokenizer;

class Main {
    static final int MOD = 1000000007;
    static final int INF = 1 << 30;
    static final int ALF = 26;

    Main() {
        FastScanner sc = new FastScanner(System.in);
        long ans = 0;
        int N = sc.nextInt();
        long K = sc.nextLong();
        int[] A = sc.nextIntArray(N);
        boolean[] visited = new boolean[N];
        ArrayList<Integer> list = new ArrayList<Integer>();
        ArrayList<Integer> out;// = new ArrayList<Integer>();
        ArrayList<Integer> in;// = new ArrayList<Integer>();
        int pos = 0;
        while (true) {
            if (visited[pos]) {
                break;
            }
            list.add(pos);
            visited[pos]=true;
            pos = A[pos];
        }
        if (pos == 0) {
            out = new ArrayList<Integer>();
            in = new ArrayList<Integer>(list);
        } else {
            int index = list.indexOf(pos);
            out = new ArrayList<Integer>(list.subList(0, index));
            in = new ArrayList<Integer>(list.subList(index, list.size()));
        }

        if (K < out.size()) {
            ans = out.get((int) K);
        } else {
            K -= out.size();
            ans = in.get((int) (K % in.size()));
        }
        //System.err.println(out.toString());
        //System.err.println(in.toString());
        System.out.println(ans+1);
    }

    public static void main(String[] args) {
        new Main();
    }
}

class FastScanner {
    private BufferedReader reader = null;
    private StringTokenizer tokenizer = null;

    public FastScanner(InputStream in) {
        reader = new BufferedReader(new InputStreamReader(in));
        tokenizer = null;
    }

    public String next() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(reader.readLine());
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }
        return tokenizer.nextToken();
    }

    public String nextLine() {
        if (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                return reader.readLine();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
        }

        return tokenizer.nextToken("\n");
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public int[] nextIntArray(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++)
            a[i] = nextInt()-1;
        return a;
    }
}
