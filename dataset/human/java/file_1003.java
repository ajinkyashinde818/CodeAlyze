import java.util.*;

class Problem {
  int n;
  long c;
  long[] x;
  long[] v;

  public Problem(int n, long c, long[] x, long[] v) {
    this.n = n;
    this.c = c;
    this.x = x;
    this.v = v;
  }

  private long[] createMaxCAscOrder() {
    long[] maxCAscOrder = new long[n];
    long currentC = 0;
    long currentP = 0;
    long prevMaxCAscOrder = 0;
    for (int i = 0; i < n; i++) {
      currentC = currentC + v[i] - (x[i] - currentP);
      currentP = x[i];
      maxCAscOrder[i] = Math.max(prevMaxCAscOrder, currentC);
      prevMaxCAscOrder = maxCAscOrder[i];
    }
/*
    System.out.println("createMaxCAscOrder");
    for (int i = 0; i < n; i++) {
      System.out.println(maxCAscOrder[i]);      
    }
    System.out.println();
*/
    return maxCAscOrder;
  }

  private long[] createMaxCDescOrder() {
    long[] maxCDescOrder = new long[n];
    long currentC = 0;
    long currentP = c;
    long prevMaxCDescOrder = 0;
    for (int i = n-1; i >= 0; i--) {
      currentC = currentC + v[i] - (currentP - x[i]);
      currentP = x[i];
      maxCDescOrder[i] = Math.max(prevMaxCDescOrder, currentC);
      prevMaxCDescOrder = maxCDescOrder[i];
    }
/*
    System.out.println("createMaxCDescOrder");
    for (int i = n-1; i >= 0; i--) {
      System.out.println(maxCDescOrder[i]);
    }
    System.out.println();
*/
    return maxCDescOrder;
  }

  private long[] createSumCAscOrder() {
    long[] sumCAscOrder = new long[n];
    sumCAscOrder[0] = v[0];
    for (int i = 1; i < n; i++) {
      sumCAscOrder[i] = sumCAscOrder[i-1] + v[i];
    }
    return sumCAscOrder;
  }

  private long[] createSumCDescOrder() {
    long[] sumCDescOrder = new long[n];
    sumCDescOrder[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
      sumCDescOrder[i] = sumCDescOrder[i+1] + v[i];
    }
    return sumCDescOrder;
  }

  public long solve() {
    long[] maxCAscOrder = createMaxCAscOrder();
    long[] maxCDescOrder = createMaxCDescOrder();
    long[] sumCAscOrder = createSumCAscOrder();
    long[] sumCDescOrder = createSumCDescOrder();
    long maxC = 0;
    maxC = Math.max(maxC, maxCAscOrder[n-1]);
//    System.out.println("maxCAscOrder[n-1]: " + maxCAscOrder[n-1]);
    maxC = Math.max(maxC, maxCDescOrder[0]);
//    System.out.println("maxCDescOrder[0]: " + maxCDescOrder[0]);
    for (int i = 0; i < n-1; i++) {
//      System.out.printf("i: %d, sumCAscOrder[i]: %d, x[i]: %d, maxCDescOrder[i+1]: %d, result: %d\n", i, sumCAscOrder[i], x[i], maxCDescOrder[i+1], sumCAscOrder[i] - 2 * x[i] + maxCDescOrder[i+1]);
      maxC = Math.max(maxC, sumCAscOrder[i] - 2 * x[i] + maxCDescOrder[i+1]);
    }
    for (int i = 1; i < n; i++) {
//      System.out.printf("i: %d, sumCDescOrder[i]: %d, c - x[i]: %d, maxCAscOrder[i-1]: %d, result: %d\n", i, sumCDescOrder[i], c - x[i], maxCAscOrder[i-1], sumCDescOrder[i] - 2 * (c - x[i]) + maxCAscOrder[i-1]);
      maxC = Math.max(maxC, sumCDescOrder[i] - 2 * (c - x[i]) + maxCAscOrder[i-1]);
    }
    return maxC;
  }
}

public class Main {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);

    int n = s.nextInt();
    long c = s.nextLong();
    long[] x = new long[n];
    long[] v = new long[n];
    for (int i = 0; i < n; i++) {
      x[i] = s.nextLong();
      v[i] = s.nextLong();
    }
    System.out.println(new Problem(n, c, x, v).solve());
  }
}
