import java.io.*;
import java.util.*;

class Count {
  final long count0, count1, count01, count10;

  Count(long count0, long count1, long count01, long count10) {
    this.count0 = count0;
    this.count1 = count1;
    this.count01 = count01;
    this.count10 = count10;
  }

  Count flip() {
    return new Count(count1, count0, count10, count01);
  }
}

public class Main {
  private static Count COUNT_EMPTY = new Count(0, 0, 0, 0);

  private static LazySegmentTree.Operator<Count, Boolean> OPERATOR = new LazySegmentTree.Operator<>(){
    @Override
    public Count e() {
      return COUNT_EMPTY;
    }

    @Override
    public Boolean id() {
      return Boolean.valueOf(true);
    }

    @Override
    public Count mapping(Boolean lazyValue, Count value, int count) {
      if (lazyValue) {
        return value;
      }
      return value.flip();
    }

    @Override
    public Boolean composition(Boolean newLazy, Boolean oldLazy) {
      return newLazy == oldLazy;
    }

    @Override
    public Count op(Count smallIndexValue, Count largeIndexValue) {
      long count0 = smallIndexValue.count0 + largeIndexValue.count0;
      long count1 = smallIndexValue.count1 + largeIndexValue.count1;
      long count01 = smallIndexValue.count01 + largeIndexValue.count01 + smallIndexValue.count0 * largeIndexValue.count1;
      long count10 = smallIndexValue.count10 + largeIndexValue.count10 + smallIndexValue.count1 * largeIndexValue.count0;
      return new Count(count0, count1, count01, count10);
    }
  };

  private static List<Long> solve(int n, int q, int[] as, int[][] tlrs) {
    Count[] counts = new Count[n];
    for (int i = 0; i < n; i++) {
      counts[i] = new Count(1 - as[i], as[i], 0, 0);
    }
    LazySegmentTree<Count, Boolean> segmentTree = new LazySegmentTree<>(OPERATOR, counts);
    List<Long> answers = new ArrayList<>();
    for (int[] tlr : tlrs) {
      int t = tlr[0];
      int l = tlr[1] - 1;
      int r = tlr[2];
      if (t == 1) {
        segmentTree.apply(l, r, Boolean.valueOf(false));
      } else {
        answers.add(segmentTree.prod(l, r).count10);
      }
    }
    return answers;
  }

  private static void execute(ContestReader reader, ContestWriter out) {
    int n = reader.nextInt();
    int q = reader.nextInt();
    int[] as = reader.nextInt(n);
    int[][] tlrs = reader.nextInt(q, 3);
    out.printList(solve(n, q, as, tlrs));
  }
  
  public static void main(String[] args) {
    ContestReader reader = new ContestReader(System.in);
    ContestWriter out = new ContestWriter(System.out);
    execute(reader, out);
    out.flush();
  }
}

class ContestWriter extends PrintWriter {
  ContestWriter(PrintStream printStream) {
    super(printStream);
  }

  public void printList(List<? extends Object> list) {
    for (Object object : list) {
      println(object);
    }
  }

  public void printListOneLine(List<? extends Object> list) {
    List<String> stringList = new ArrayList<>();
    for (Object object : list) {
      stringList.add(object.toString());
    }
    println(String.join(" ", stringList));
  }
}

class LazySegmentTree<S, F> {
  public interface Operator<S, F> {
    S e();
    F id();
    S mapping(F lazyValue, S value, int count);
    F composition(F newLazy, F oldLazy);
    S op(S smallIndexValue, S largeIndexValue);
  }

  private final Operator<S, F> operator;
  private final int n, log, size;
  private final S[] d;
  private final F[] lz;

  private static int ceil_pow2(int n) {
    int x = 0;
    while ((1 << x) < n) {
      x++;
    }
    return x;
  }

  public LazySegmentTree(Operator<S, F> operator, S[] v) {
    this.operator = operator;
    this.n = v.length;
    this.log = ceil_pow2(n);
    this.size = 1 << log;
    this.d = (S[])new Object[2 * size];
    Arrays.fill(this.d, this.operator.e());
    this.lz = (F[])new Object[size];
    Arrays.fill(this.lz, this.operator.id());
    for (int i = 0; i < n; i++) {
      this.d[size + i] = v[i];
    }
    for (int i = size - 1; i >= 1; i--) {
      update(i);
    }
  }

  public void set(int p, S x) {
//    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) {
      push(p >> i);
    }
    d[p] = x;
    for (int i = 1; i <= log; i++) {
      update(p >> i);
    }
  }

  public S get(int p) {
//    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) {
      push(p >> i);
    }
    return d[p];
  }

  public S prod(int l, int r) {
//    assert(0 <= l && l <= r && r <= n);
    if (l == r) {
      operator.e();
    }
    l += size;
    r += size;
    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) {
        push(l >> i);
      }
      if (((r >> i) << i) != r) {
        push(r >> i);
      }
    }
    S lValue = operator.e();
    S rValue = operator.e();
    while (l < r) {
      if ((l & 1) == 1) {
        lValue = operator.op(lValue, d[l]);
        l++;
      }
      if ((r & 1) == 1) {
        r--;
        rValue = operator.op(d[r], rValue);
      }
      l >>= 1;
      r >>= 1;
    }
    return operator.op(lValue, rValue);
  }

  public S allProd() {
    return d[1];
  }

  public void apply(int p, F f) {
//    assert(0 <= p && p < n);
    p += size;
    for (int i = log; i >= 1; i--) {
      push(p >> i);
    }
    d[p] = operator.mapping(f, d[p], 1);
    for (int i = 1; i <= log; i++) {
      update(p >> i);
    }
  }

  public void apply(int l, int r, F f) {
//    assert(0 <= l && l <= r && r <= n);
    if (l == r) {
      return;
    }

    l += size;
    r += size;

    for (int i = log; i >= 1; i--) {
      if (((l >> i) << i) != l) {
        push(l >> i);
      }
      if (((r >> i) << i) != r) {
        push((r - 1) >> i);
      }
    }

    {
      int l2 = l;
      int r2 = r;
      while (l < r) {
        if ((l & 1) == 1) {
          allApply(l, f);
          l++;
        }
        if ((r & 1) == 1) {
          r--;
          allApply(r, f);
        }
        l >>= 1;
        r >>= 1;
      }
      l = l2;
      r = r2;
    }

    for (int i = 1; i <= log; i++) {
      if (((l >> i) << i) != l) {
        update(l >> i);
      }
      if (((r >> i) << i) != r) {
        update((r - 1) >> i);
      }
    }
  }

  private void update(int k) {
    d[k] = this.operator.op(d[2 * k], d[2 * k + 1]);
  }

  private void allApply(int k, F f) {
    int count = 1 << (Integer.numberOfLeadingZeros(k) - 31 + log);
//    System.err.printf("k: %d, count: %d\n", k, count);
    d[k] = this.operator.mapping(f, d[k], count);
    if (k < size) {
      lz[k] = this.operator.composition(f, lz[k]);
    }
  }

  private void push(int k) {
    allApply(2 * k, lz[k]);
    allApply(2 * k + 1, lz[k]);
    lz[k] = this.operator.id();
  }
}

class ContestReader {
  private static final int BUFFER_SIZE = 1024;
  
  private final InputStream stream;
  private final byte[] buffer;
  private int pointer;
  private int bufferLength;
  
  ContestReader(InputStream stream) {
    this.stream = stream;
    this.buffer = new byte[BUFFER_SIZE];
    this.pointer = 0;
    this.bufferLength = 0;
  }
  
  private boolean hasNextByte() {
    if (pointer < bufferLength) {
      return true;
    }
    
    pointer = 0;
    try {
      bufferLength = stream.read(buffer);
    } catch (IOException e) {
      throw new RuntimeException(e);
    }
    return bufferLength > 0;
  }
  
  private int readByte() {
    if (hasNextByte()) {
      return buffer[pointer++];
    } else {
      return -1;
    }
  }
  
  private static boolean isPrintableChar(int c) {
    return 33 <= c && c <= 126;
  }
  
  public boolean hasNext() {
    while (hasNextByte() && !isPrintableChar(buffer[pointer])) {
      pointer++;
    }
    return hasNextByte();
  }
  
  public String next() {
    if (!hasNext()) {
      throw new NoSuchElementException();
    }
    StringBuilder sb = new StringBuilder();
    while(true) {
      int b = readByte();
      if (!isPrintableChar(b)) {
        break;
      }
      sb.appendCodePoint(b);
    }
    return sb.toString();
  }
  
  public String nextLine() {
    if (!hasNext()) {
      throw new NoSuchElementException();
    }
    StringBuilder sb = new StringBuilder();
    while(true) {
      int b = readByte();
      if (!isPrintableChar(b) && b != 0x20) {
        break;
      }
      sb.appendCodePoint(b);
    }
    return sb.toString();
  }
  
  public char nextChar() {
    return next().charAt(0);
  }
  
  public int nextInt() {
    if (!hasNext()) {
      throw new NoSuchElementException();
    }
    
    int n = 0;
    boolean minus = false;
    
    {
      int b = readByte();
      if (b == '-') {
        minus = true;
      } else if ('0' <= b && b <= '9') {
        n = b - '0';
      } else {
        throw new NumberFormatException();
      }
    }
    
    while(true){
      int b = readByte();
      if ('0' <= b && b <= '9') {
        n *= 10;
        n += b - '0';
      } else if (b == -1 || !isPrintableChar(b)) {
        return minus ? -n : n;
      } else {
        throw new NumberFormatException();
      }
    }
  }
  
  public long nextLong() {
    if (!hasNext()) {
      throw new NoSuchElementException();
    }
    
    long n = 0;
    boolean minus = false;
    
    {
      int b = readByte();
      if (b == '-') {
        minus = true;
      } else if ('0' <= b && b <= '9') {
        n = b - '0';
      } else {
        throw new NumberFormatException();
      }
    }
    
    while(true){
      int b = readByte();
      if ('0' <= b && b <= '9') {
        n *= 10;
        n += b - '0';
      } else if (b == -1 || !isPrintableChar(b)) {
        return minus ? -n : n;
      } else {
        throw new NumberFormatException();
      }
    }
  }
  
  public double nextDouble() {
    return Double.parseDouble(next());
  }
  
  public String[] next(int n) {
    String[] array = new String[n];
    for (int i = 0; i < n; i++) {
      array[i] = next();
    }
    return array;
  }
  
  public String[] nextLine(int n) {
    String[] array = new String[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextLine();
    }
    return array;
  }
  
  public char[] nextChar(int n) {
    char[] array = new char[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextChar();
    }
    return array;
  }
  
  public int[] nextInt(int n) {
    int[] array = new int[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextInt();
    }
    return array;
  }
  
  public long[] nextLong(int n) {
    long[] array = new long[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextLong();
    }
    return array;
  }
  
  public double[] nextDouble(int n) {
    double[] array = new double[n];
    for (int i = 0; i < n; i++) {
      array[i] = nextDouble();
    }
    return array;
  }
  
  public char[] nextCharArray() {
    return next().toCharArray();
  }
  
  public String[][] next(int n, int m) {
    String[][] matrix = new String[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = next();
      }
    }
    return matrix;
  }
  
  public int[][] nextInt(int n, int m) {
    int[][] matrix = new int[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextInt();
      }
    }
    return matrix;
  }
  
  public char[][] nextChar(int n, int m) {
    char[][] matrix = new char[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextChar();
      }
    }
    return matrix;
  }
  
  public long[][] nextLong(int n, int m) {
    long[][] matrix = new long[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextLong();
      }
    }
    return matrix;
  }
  
  public double[][] nextDouble(int n, int m) {
    double[][] matrix = new double[n][m];
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        matrix[i][j] = nextDouble();
      }
    }
    return matrix;
  }
  
  public char[][] nextCharArray(int n) {
    char[][] matrix = new char[n][];
    for (int i = 0; i < n; i++) {
      matrix[i] = next().toCharArray();
    }
    return matrix;
  }
}

class MyAssert {
  public static void myAssert(boolean flag, String message) {
    if (!flag) {
      throw new RuntimeException(message);
    }
  }
 
  public static void myAssert(boolean flag) {
    myAssert(flag, "");
  }
}
