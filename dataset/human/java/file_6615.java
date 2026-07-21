import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {
  private static void solve() {
//    int n = 8000;
//    char[] s = new char[n];
//    for (int i = 0; i < n; i ++) {
//      
//      s[i] = 'F';
//      if (i % 2 == 1) {
//        s[i] = 'T';
//      }
//    }
//    int x = 0;
//    int y = 0;
    char[] s = ns();
    int x = ni();
    int y = ni();

    List<Integer> listX = new ArrayList<>();
    List<Integer> listY = new ArrayList<>();
    
    int ptr = 0;
    int startX = 0;
    while (ptr < s.length && s[ptr] != 'T') {
      startX ++;
      ptr ++;
    }
    
    int count = 0;
    boolean dx = true;
    for (; ptr <= s.length; ptr ++) {
      if (ptr == s.length || s[ptr] == 'T') {
        if (count > 0) {
          if (dx) {
            listX.add(count);
          } else {
            listY.add(count);
          }
        }
        dx = !dx;
        count = 0;
      } else {
        count ++;
      }
    }
    
    
    boolean retX = f(listX, startX, x);
    boolean retY = f(listY, 0, y);
    System.out.println(retX && retY ? "Yes" : "No");
//
//    System.out.println(listX);
//    System.out.println(listY);
//    System.out.println(x);
//    System.out.println(y);
//    
//    System.out.println(retX);
//    System.out.println(retY);
  }
  
  private static boolean f(List<Integer> list, int now, int target) {
    boolean[][] dp = new boolean[2][20000];
    int offset = 10000;

    int n = list.size();
    dp[0][offset + now] = true;
    for (int i = 0; i < n; i ++) {
      int from = (i % 2);
      int to = (i + 1) % 2;
      
      int d = list.get(i);
      for (int x = -9000; x <= 9000; x ++) {
        if (-9000 <= x + d && x + d <= 9000)
          dp[to][offset + x + d] |= dp[from][offset + x];
        if (-9000 <= x - d && x - d <= 9000)
          dp[to][offset + x - d] |= dp[from][offset + x];
      }
      Arrays.fill(dp[from], false);
    }
    return dp[n % 2][offset + target];
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
