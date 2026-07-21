import java.io.*;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    new Main().run();
  }

  private void run() {
    try(BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out)) {

          final int mod = 1_000_000_007;

          String[] ln = in.readLine().split(" ");
          final int n = atoi(ln[0]);
          final int m = atoi(ln[1]);

          boolean[] isBroken = new boolean[n+2];
          for (int i = 0; i < m; i++) {
            int x = atoi(in.readLine());
            isBroken[x] = true;
          }

          long[] dp = new long[n+2];
          dp[0] = 1L;
          for (int i = 0; i < n; i++) {
            for (int j = i+1; j <= i+2; j++) {
              if(!isBroken[j]) {
                dp[j] += dp[i];
                dp[j] %= mod;
              }
            }
          }

          final long ans = dp[n];
          out.println(ans);
    }
    catch(IOException e) {
      System.err.println(e);
    }
  }

  int  atoi(String s) { return Integer.parseInt(s); }
  long atol(String s) { return Long.parseLong(s);   }
}
