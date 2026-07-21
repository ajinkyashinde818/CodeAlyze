import java.util.Scanner;

public class Main {
  public static void main (String[] args) {
    Scanner in = new Scanner(System.in);

    while (in.hasNext()) {
      int N = in.nextInt();
      int[] A = new int[N];
      int countNeg = 0;
      int absMin = Integer.MAX_VALUE;
      long absSum = 0;

      for (int i = 0; i < A.length; ++i) {
        A[i] = in.nextInt();
        absSum += Math.abs(A[i]);
        absMin = Math.min(absMin, Math.abs(A[i]));

        if (A[i] < 0) {
          ++countNeg;
        }
      }
      
      if (countNeg % 2 == 0) {
        System.out.println(absSum);
      } else {
        System.out.println(absSum - absMin * 2);
      }
    }
  }
}
