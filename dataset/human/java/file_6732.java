import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int[] A = new int[N];
    int min = Integer.MAX_VALUE;

    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }

    for (int i = 0; i < N; i++) {
      int tokeiEnd = (i == 0 ? N-1 : i);
      int hantokeiEnd = (i == N-1 ? 0 : i+1);

      int tokei = tokei(A[i], A[tokeiEnd], K);
      if (tokei < min) {
        min = tokei;
      }

      int hantokei = hantokei(A[i], A[hantokeiEnd], K);
      if (hantokei < min) {
        min = hantokei;
      }
    }

    System.out.println(min);

  }

  public static int tokei(int begin, int end, int K) {
    if (begin < end) {
      return end - begin;
    } else {
      return K - begin + end;
    }
  }

  public static int hantokei(int begin, int end, int K) {
    if (begin > end) {
      return begin - end;
    } else {
      return begin + (K - end);
    }
  }

}
