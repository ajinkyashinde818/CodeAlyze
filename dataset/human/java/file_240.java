import java.util.Scanner;

class Main {

  private static long INF = Long.MAX_VALUE / 4;

  public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);
    int N = scanner.nextInt();
    long[] A = new long[N];
    long[] comSum = new long[N + 1];
    boolean flag = false;
    for (int i = 0; i < N; i++) {
      A[i] = scanner.nextLong();
      comSum[i + 1] = comSum[i] + Math.abs(A[i]);
      if (A[i] == 0) {
        flag = true;
      }
    }
    long min = INF;
    for (int i = 0; i < N; i++) {
      if (Math.abs(min) > Math.abs(A[i])) {
        min = A[i];
      }
    }
    int cnt = 0;
    for (int i = 0; i < N; i++) {
      if (A[i] < 0) {
        cnt++;
      }
    }
    if (flag || cnt % 2 == 0) {
      System.out.println(comSum[N]);
    } else {
      System.out.println(comSum[N] - 2 * Math.abs(min));
    }
  }

}
