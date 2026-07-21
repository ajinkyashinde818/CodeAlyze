/**
 * Created at 04:21 on 2019-08-16
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

  public static class Solver {
    public Solver() {

      int D = sc.nextInt();
      long G = sc.nextLong();

      Problem[] problems = new Problem[D];
      for (int i=0; i<D; i++) {
        problems[i] = new Problem(i+1, sc.nextInt(), sc.nextInt());
      }

      long ans = INF;
      for (Bit bit = new Bit(); !bit.get(D); bit.next()) {
        long sum = 0;
        int count = 0;
        for (int i = bit.nextSetBit(0); i>=0; i=bit.nextSetBit(i+1)) {
          sum += problems[i].completeScore;
          count += problems[i].p;
        }

        if (sum >= G) {
          ans = Math.min(ans, count);
          continue;
        }

        for (int i = bit.previousClearBit(D-1); i>=0; i=bit.previousClearBit(i-1)) {
          long need = (G - sum + (i+1) * 100 - 1) / ((i+1) * 100);
          if (need < problems[i].p) {
            count += need;
            ans = Math.min(ans, count);
          }
        }
      }

      out.println(ans);


    }

    public class Problem {
      int i;
      long p, c;
      long completeScore;
      Problem (int i, long p, long c) {
        this.p = p;
        this.c = c;
        completeScore = p * i * 100 + c;
      }
    }

    public class Bit extends BitSet {

      public void set(long l) {
        clear();
        for (int i=0; i<64; i++) {
          if (((l>>i)&1) == 1) set(i, true);
        }
      }

      public long toLong() {
        long res = 0;
        for (int i = nextSetBit(0); i >= 0; i = nextSetBit(i+1)) {
          res += 1<<i;
        }
        return res;
      }

      public void next() {
        for (int i=0; ; i++) {
          if (get(i)) {
            set(i, false);
          } else {
            set(i, true);
            break;
          }
        }
      }

    }

  }

  public static void main(String[] args) {
    new Solver();
    out.flush();
  }

  static class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

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
  }

}
