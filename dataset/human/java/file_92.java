import java.util.*;
import java.util.stream.*;

public class Main {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    int[] A = new int[N];
    int cnt = 0, min = Integer.MAX_VALUE;
    boolean zero = false;
    long ans = 0;
    for (int i = 0; i < N; i++) {
      A[i] = in.nextInt();
      ans += Math.abs(A[i]);
      min = Math.min(min, Math.abs(A[i]));
      if (A[i] < 0) {
        cnt++;
      }
      if (A[i] == 0) {
        zero = true;
      }

    }
    if (cnt % 2 == 0 || zero) {
      System.out.println(ans);
    } else {
      System.out.println(ans - min * 2);
    }
  }
}
