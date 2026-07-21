import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.stream.Collectors;
import java.util.stream.LongStream;

class Main {

  static class Solver {
    final FastScanner sc;
    final PrintWriter writer;

    Solver(final FastScanner sc, final PrintWriter writer) {
      this.sc = sc;
      this.writer = writer;
    }

    void run() {
      int n = sc.nextInt();
      int k = sc.nextInt();
      int s = sc.nextInt();
      int padding = s + 1;
      if (s == 1000000000) {
        padding = 1;
      }
      List<Integer> result = new ArrayList<>();
      for (int i = 0; i < k; i++) {
        result.add(s);
      }
      for (int i = k; i < n; i++) {
        result.add(padding);
      }
      String resultStr = result.stream().map(i -> i.toString()).collect(Collectors.joining(" "));
      writer.println(resultStr);
    }
  }

  public static void main(final String[] args) {
    final FastScanner sc = new FastScanner();
    try (final PrintWriter w = new PrintWriter(System.out)) {
      new Solver(sc, w).run();
      w.flush();
    }
  }

  // CRT stuff
  static class MOD {
    private static final int MOD = (int) 1e9 + 7;

    static long plus(long x, long y) {
      x %= MOD;
      y %= MOD;
      return (x + y) % MOD;
    }

    static long sub(long x, long y) {
      x %= MOD;
      y %= MOD;
      return (x - y + MOD) % MOD;
    }

    static long multi(long x, long y) {
      x %= MOD;
      y %= MOD;
      return x * y % MOD;
    }

    static long div(long x, long y) {
      x %= MOD;
      y %= MOD;
      return x * pow(y, MOD - 2) % MOD;
    }

    static long pow(final long a, final long p) {
      if (p == 0)
        return 1;
      if (p % 2 == 0) {
        final long halfP = p / 2;
        final long root = pow(a, halfP);
        return root * root % MOD;
      } else
        return a * pow(a, p - 1) % MOD;
    }
  }

  // FastScanner
  static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    public FastScanner() {
    }

    private boolean hasNextByte() {
      if (ptr < buflen) {
        return true;
      } else {
        ptr = 0;
        try {
          buflen = in.read(buffer);
        } catch (final IOException e) {
          e.printStackTrace();
        }
        if (buflen <= 0) {
          return false;
        }
      }
      return true;
    }

    private int readByte() {
      if (hasNextByte())
        return buffer[ptr++];
      else
        return -1;
    }

    private boolean isPrintableChar(final int c) {
      return 33 <= c && c <= 126;
    }

    public boolean hasNext() {
      while (hasNextByte() && !isPrintableChar(buffer[ptr]))
        ptr++;
      return hasNextByte();
    }

    public String next() {
      if (!hasNext())
        throw new NoSuchElementException();
      final StringBuilder sb = new StringBuilder();
      int b = readByte();
      while (isPrintableChar(b)) {
        sb.appendCodePoint(b);
        b = readByte();
      }
      return sb.toString();
    }

    public long nextLong() {
      if (!hasNext())
        throw new NoSuchElementException();
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
      final long nl = nextLong();
      if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE)
        throw new NumberFormatException();
      return (int) nl;
    }

    public double nextDouble() {
      return Double.parseDouble(next());
    }

    public int[] nextIntArray(final int n) {
      final int[] a = new int[n];
      for (int i = 0; i < n; i++)
        a[i] = nextInt();
      return a;
    }

    public long[] nextLongArray(final int n) {
      final long[] a = new long[n];
      for (int i = 0; i < n; i++)
        a[i] = nextLong();
      return a;
    }
  }
}
