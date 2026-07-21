/**
 * Created at 21:03 on 2019-12-22
 */

import java.io.*;
import java.util.*;

public class Main {

  static FastScanner sc = new FastScanner();
  static Output out = new Output(System.out);

  static final int[] dx = {0, 1, 0, -1};
  static final int[] dy = {-1, 0, 1, 0};

  static final long MOD = (long) (1e9 + 7);
  static final long INF = Long.MAX_VALUE / 2;

  static final int e5 = (int) 1e5;

  public static class Solver {
    public Solver() {

      long A = sc.nextLong();
      long B = sc.nextLong();

      out.println(A * B / Mathf.gcd(A, B));

    }

    public static class Mathf {

      private static long[][] comb;

      /*
       * nCrを返す
       * 比較的小さい値でないとオーバーフローする
       */
      public static long comb(int n, int r) {
        if (comb[n][r] != 0) return comb[n][r];
        if (r < 0 || r > n) return 0;
        return comb[n][r] = comb(n-1, r-1) + comb(n-1, r);
      }

      public static void combInit(int maxN) {
        comb = new long[maxN+1][maxN+1];
        for (int i=0; i<=maxN; i++) {
          comb[i][0] = 1;
        }
      }

      /*
       * 約数を小さい順に並べた配列を返す
       */
      public static int[] getFactors(int n) {
        ArrayList<Integer> f1 = new ArrayList();
        ArrayList<Integer> f2 = new ArrayList();
        int bound = (int)Math.sqrt(n);
        for (int i=1; i<=bound; i++) {
          if (n % i == 0) {
            f1.add(i);
            f2.add(n/i);
          }
        }

        if (bound * bound == n) f2.remove(f2.size()-1);

        int[] factors = new int[f1.size() + f2.size()];

        for (int i=0; i<f1.size(); i++) {
          factors[i] = f1.get(i);
        }

        for (int i=0; i<f2.size(); i++) {
          factors[f1.size()+i] = f2.get(f2.size()-i-1);
        }

        return factors;
      }

      /*
       * ans[i] ... 素因数iがいくつ含まれるかを表す
       */
      public int[] factorize(int n) {
        int bound = (int)Math.sqrt(n);
        int[] ans = new int[n+1];

        for (int i=2; i<=bound; i++) {
          if (n == 1) break;
          while (n % i == 0) {
            ans[i]++;
            n /= i;
          }
        }

        if (n != 1) {
          ans[n] = 1;
        }

        return ans;
      }

      /*
       * ans[i] ... 素因数iがいくつ含まれるかを表す
       * sqrt(n) より大きい素因数はans[0], ans[1]に分けて収納する
       * ((long)ans[1]<<32) + ans[0]で取り出すことができる(なかった場合は1が取り出される)
       */
      public int[] factorizeL(long n) {
        int bound = (int)Math.sqrt(n);
        int[] ans = new int[bound+1];

        for (int i=2; i<=bound; i++) {
          if (n == 1) break;
          while (n % i == 0) {
            ans[i]++;
            n /= i;
          }
        }

        ans[0] = (int)n;
        ans[1] = (int)(n >> 32);

        return ans;
      }

      /*
       * 区間[a, b]の中でqで割ってr余るものの個数
       * r = 0 なら区間[a, b]の中でqの倍数であるものの個数
       * a <= b, 0 <= r < q
       */
      public long count_nq_r(long a, long b, long q, long r) {
        r %= q;
        return (floor(b-r,q)+1) - (floor(a-1-r, q)+1);
      }

      /*
       * a を b で割った商を返す
       */
      public long q(long a, long b) {
        if (b > 0) {
          return floor(a, b);
        } else {
          return ceil(a, b);
        }
      }

      /*
       * a を b で割った余りを返す
       */
      public long r(long a, long b) {
        return a - q(a, b) * b;
      }

      /*
       * nの平方根の整数部分を返す
       * doubleの精度に限界があるので微調整する
       */
      long sqrt(long n) {
        long res = (long)Math.floor(Math.sqrt(n));
        while (res * res > n) res--;
        while ((res+1) * (res+1) <= n) res++;
        return res;
      }

      /*
       * n <= a/b なる最大の整数nを返す
       */
      public long floor(long a, long b) {
        if (b < 0) {
          a *= -1;
          b *= -1;
        }

        if (a > 0) {
          //絶対値の小さい方に丸められる(正なら負の方向)
          return a/b;
        } else {
          //よくある切り上げのテクニックの切り捨て版
          return (a-b+1)/b;
        }
      }

      /*
       * n >= a/b なる最小の整数nを返す
       */
      public long ceil(long a, long b) {
        if (b < 0) {
          a *= -1;
          b *= -1;
        }

        if (a > 0) {
          //よくある切り上げのテクニック
          return (a+b-1)/b;
        } else {
          //絶対値の小さい方に丸められる(負なら正の方向)
          return a/b;
        }
      }

      public long lcm(long a, long b) {
        return a * b / gcd(a, b);
      }

      public static long gcd(long a, long b) {
        long M = Math.max(a, b);
        long m = Math.min(a, b);

        if (m == 0) {
          return M;
        }

        return gcd(m, M%m);
      }


    }

  }

  public static void main(String[] args) {
    new Solver();
    out.flush();
  }

  static class FastScanner {
    private InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;


    public void load() {
      try {
        in = new FileInputStream(next());
      } catch (Exception e) {
        e.printStackTrace();
      }
    }

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte()) return buffer[ptr++];
      else return -1;
    }

    private static boolean isPrintableChar(int c) {
      return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++;
    }

    public boolean hasNext() {
      skipUnprintable();
      return hasNextByte();
    }

    public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    public long nextLong() {
      if (!hasNext()) throw new NoSuchElementException();
      long n = 0;
      boolean minus = false;
      int b = readByte();
      if (b == '-') {
        minus = true;
        b = readByte();
      }
      if (b < '0' || '9' < b) {
        throw new NumberFormatException();
      }
      while (true) {
        if ('0' <= b && b <= '9') {
          n *= 10;
          n += b - '0';
        } else if (b == -1 || !isPrintableChar(b)) {
          return minus ? -n : n;
        } else {
          throw new NumberFormatException();
        }
        b = readByte();
      }
    }

    public int nextInt() {
      return (int) nextLong();
    }

    public int[] nextIntArray(int N, boolean oneBased) {
      if (oneBased) {
        int[] array = new int[N + 1];
        for (int i = 1; i <= N; i++) {
          array[i] = sc.nextInt();
        }
        return array;
      } else {
        int[] array = new int[N];
        for (int i = 0; i < N; i++) {
          array[i] = sc.nextInt();
        }
        return array;
      }
    }

    public long[] nextLongArray(int N, boolean oneBased) {
      if (oneBased) {
        long[] array = new long[N + 1];
        for (int i = 1; i <= N; i++) {
          array[i] = sc.nextLong();
        }
        return array;
      } else {
        long[] array = new long[N];
        for (int i = 0; i < N; i++) {
          array[i] = sc.nextLong();
        }
        return array;
      }
    }
  }

  static class Output extends PrintWriter {

    private long startTime;

    public Output(PrintStream ps) {
      super(ps);
    }

    public void print(int[] a, String separator) {
      for (int i = 0; i < a.length; i++) {
        if (i == 0) print(a[i]);
        else print(separator + a[i]);
      }
      println();
    }

    public void print(long[] a, String separator) {
      for (int i = 0; i < a.length; i++) {
        if (i == 0) print(a[i]);
        else print(separator + a[i]);
      }
      println();
    }

    public void print(String[] a, String separator) {
      for (int i = 0; i < a.length; i++) {
        if (i == 0) print(a[i]);
        else print(separator + a[i]);
      }
      println();
    }

    public void print(ArrayList a, String separator) {
      for (int i = 0; i < a.size(); i++) {
        if (i == 0) print(a.get(i));
        else print(separator + a.get(i));
      }
      println();
    }

    public void start() {
      startTime = System.currentTimeMillis();
    }

    public void time(String s) {
      long time = System.currentTimeMillis() - startTime;
      println(s + "(" + time + ")");
    }

  }

}
