import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {
  private static class FastScanner {
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
        a[i] = nextInt();
      return a;
    }

    public long[] nextLongArray(int n) {
      long[] a = new long[n];
      for (int i = 0; i < n; i++)
        a[i] = nextLong();
      return a;
    }
  }

  public static void main(String[] args) {
    FastScanner sc = new FastScanner(System.in);
    int n = sc.nextInt();
    int m = sc.nextInt();
    int x = sc.nextInt();
    int[] c = new int[n];
    int[][] a = new int[n][m];
    for (int i = 0; i < n; i++) {
      c[i] = sc.nextInt();
      for (int j = 0; j < m; j++) {
        a[i][j] = sc.nextInt();
      }
    }
    boolean find = false;
    int min = Integer.MAX_VALUE;
    for (int i = 0; i < (1 << n); i++) {
      int[] sum = new int[m];
      int total = 0;
      for (int j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0) continue;
        total += c[j];
        for (int k = 0; k < m; k++) {
          sum[k] += a[j][k];
        }
      }
      boolean ok = true;
      for (int s : sum) {
        if (s < x) {
          ok = false;
          break;
        }
      }
      if (ok && min > total) {
        min = total;
        find = true;
      }
    }
    System.out.println(find ? min : -1);
  }
}
