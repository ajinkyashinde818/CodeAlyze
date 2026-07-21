import java.util.*;

public class Main {

  public static void main (String[] args) {

    Scanner sc = new Scanner(System.in);

    int N = sc.nextInt();
    int[] A = new int[N];
    int count = 0;
    long sum = 0;

    for (int i = 0; i < N; i++) {
      int v = sc.nextInt();
      if (v < 0) {
        count++;
      }
      A[i] = Math.abs(v);
      sum += A[i];
    }

    sc.close();

    Arrays.sort(A);
   
    if (count % 2 != 0) {
      sum -= (2 * A[0]);
    }

    System.out.println(sum);

  }

}
