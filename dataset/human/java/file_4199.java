import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      int N = in.nextInt();
      int[] A = new int[N];
      int[] B = new int[N];
      int[] C = new int[N - 1];
      int satisfaction = 0;

      for (int i = 0; i < A.length; ++i) {
        A[i] = in.nextInt();
      }


      for (int i = 0; i < B.length; ++i) {
        B[i] = in.nextInt();
        satisfaction += B[i];
      }

      for (int i = 0; i < C.length; ++i) {
        C[i] = in.nextInt();
      }

      for (int i = 1; i < A.length; ++i) {
        if (A[i] - 1 == A[i - 1]) {
          satisfaction += C[A[i - 1] - 1];
        }
      }

      System.out.println(satisfaction);
    }
  }
}
