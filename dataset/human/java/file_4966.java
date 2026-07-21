import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.HashMap;
import java.util.Map;
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
    String s = sc.next();
    Map<Integer, String> ans = new HashMap<>();
    ans.put(0, s);
    boolean forward = true;
    int min = 0;
    int max = 0;
    int q = sc.nextInt();
    while (q-- > 0) {
      int t = sc.nextInt();
      if (t == 1) {
        forward = !forward;
        continue;
      }
      int f = sc.nextInt();
      String c = sc.next();
      if ((forward && f == 2) || (!forward && f == 1)) {
        ans.put(max + 1, c);
        max++;
      } else {
        ans.put(min - 1, c);
        min--;
      }
    }
    StringBuilder sb = new StringBuilder();
    if (max == min) {
      sb.append(ans.get(0));
    } else if (forward) {
      for (int i = min; i <= max; i++) {
        sb.append(ans.get(i));
      }
    } else {
      for (int i = max; i >= min; i--) {
        if (i == 0) {
          StringBuilder revS = new StringBuilder(s);
          sb.append(revS.reverse().toString());
        } else{
          sb.append(ans.get(i));
        }
      }
    }
    System.out.println(sb.toString());
  }
}
