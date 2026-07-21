import java.util.*;
import java.io.*;
import static java.lang.System.*;

class FastScanner {
  private final InputStream in = System.in;
  private final byte[] buffer = new byte[1024];
  private int ptr = 0;
  private int buflen = 0;
  private boolean hasNextByte() {
      if (ptr < buflen) {
          return true;
      }else{
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
  private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
  private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
  public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
  public String next() {
      if (!hasNext()) throw new NoSuchElementException();
      StringBuilder sb = new StringBuilder();
      int b = readByte();
      while(isPrintableChar(b)) {
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
      while(true){
          if ('0' <= b && b <= '9') {
              n *= 10;
              n += b - '0';
          }else if(b == -1 || !isPrintableChar(b)){
              return minus ? -n : n;
          }else{
              throw new NumberFormatException();
          }
          b = readByte();
      }
  }
  public int nextInt() {
      long nl = nextLong();
      if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
      return (int) nl;
  }
  public double nextDouble() { return Double.parseDouble(next());}
}

class Main {
  public static final int MOD = 1000000007;
  public static final int INF = 1000000000;
  public static void main(String[] args) {
    FastScanner sc = new FastScanner();
    int D = sc.nextInt();
    int G = sc.nextInt();
    int p[] = new int[D];
    int c[] = new int[D];
    for(int i=0; i<D; i++){
      p[i] = sc.nextInt();
      c[i] = sc.nextInt();
    }
    int ans = INF;
    for(int n=0; n<(1<<D); n++){
      int point = 0;
      int maxindex = 0;
      int cnt = 0;
      for(int i=0; i<D; i++){
        if((n>>i & 1) == 1){
          point += 100 * (i+1) * p[i] + c[i];
          cnt += p[i];
        }else{
          maxindex = i;
        }
      }
      if(G > point){
        int need = (G - point + (maxindex+1) * 100 - 1) / ((maxindex+1) * 100);
        if(need >= p[maxindex]) continue;
        cnt += need;
      }
      ans = Math.min(ans, cnt);
    }
    out.println(ans);
  }

  public static int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
  }
}
