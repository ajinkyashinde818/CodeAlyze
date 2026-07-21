import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int[] a = new int[N];
    for (int i = 0; i < N; i++) {
      a[i] = sc.nextInt();
    }
    long[] leftSum = new long[N];
    long[] rightSum = new long[N];
    leftSum[0] = a[0];
    rightSum[N-1] = a[N-1];
    for (int i = 1; i < N; i++) {
      leftSum[i] = a[i] + leftSum[i-1];
      rightSum[N-1-i] = a[N-1-i] + rightSum[N-i];
    }
    
    long min = Long.MAX_VALUE;
    for (int i = 0; i < N-1; i++) {
      min = Math.min(min, Math.abs(leftSum[i]-rightSum[i+1]));
    }
    
    System.out.println(min);
  }
}
