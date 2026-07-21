public class Main {


  private static void solve() {
    int n = ni();
    for (int k = 1; k <= 1000; k ++) {
      if (k * (k - 1) / 2 == n) {
        build(n, k);
        return;
      }
    }
    System.out.println("No");
  }
  
  private static void build(int n, int k) {
    int len = n * 2 / k;
    int[][] a = new int[k][len];

    int now = 0;
    for (int i = 0; i < len; i ++) {
      for (int j = 0; j < (len - i); j ++) {
        a[i][j + i] = now + j;
        a[j + i + 1][i] = now + j;
      }
      now += len - i;
    }

    StringBuilder sb = new StringBuilder();
    sb.append(k);
    sb.append("\n");
    for (int i = 0; i < k; i ++) {
      sb.append(len + " ");
      for (int j = 0; j < len; j ++) {
        sb.append(a[i][j] + 1);
        if (j < len - 1) {
          sb.append(" ");
        } else {
          sb.append("\n");
        }
      }
    }
    System.out.println("Yes");
    System.out.println(sb);
  }

  public static void main(String[] args) {
    new Thread(null, new Runnable() {
      @Override
      public void run() {
        long start = System.currentTimeMillis();
        String debug = args.length > 0 ? args[0] : null;
        if (debug != null) {
          try {
            is = java.nio.file.Files.newInputStream(java.nio.file.Paths.get(debug));
          } catch (Exception e) {
            throw new RuntimeException(e);
          }
        }
        reader = new java.io.BufferedReader(new java.io.InputStreamReader(is), 32768);
        solve();
        out.flush();
        tr((System.currentTimeMillis() - start) + "ms");
      }
    }, "", 64000000).start();
  }

  private static java.io.InputStream is = System.in;
  private static java.io.PrintWriter out = new java.io.PrintWriter(System.out);
  private static java.util.StringTokenizer tokenizer = null;
  private static java.io.BufferedReader reader;

  public static String next() {
    while (tokenizer == null || !tokenizer.hasMoreTokens()) {
      try {
        tokenizer = new java.util.StringTokenizer(reader.readLine());
      } catch (Exception e) {
        throw new RuntimeException(e);
      }
    }
    return tokenizer.nextToken();
  }

  private static double nd() {
    return Double.parseDouble(next());
  }

  private static long nl() {
    return Long.parseLong(next());
  }

  private static int[] na(int n) {
    int[] a = new int[n];
    for (int i = 0; i < n; i++)
      a[i] = ni();
    return a;
  }

  private static char[] ns() {
    return next().toCharArray();
  }

  private static long[] nal(int n) {
    long[] a = new long[n];
    for (int i = 0; i < n; i++)
      a[i] = nl();
    return a;
  }

  private static int[][] ntable(int n, int m) {
    int[][] table = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[i][j] = ni();
      }
    }
    return table;
  }

  private static int[][] nlist(int n, int m) {
    int[][] table = new int[m][n];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        table[j][i] = ni();
      }
    }
    return table;
  }

  private static int ni() {
    return Integer.parseInt(next());
  }

  private static void tr(Object... o) {
    if (is != System.in)
      System.out.println(java.util.Arrays.deepToString(o));
  }
}
