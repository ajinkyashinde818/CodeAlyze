import java.util.Scanner;
import java.util.Arrays;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int K = scan.nextInt();
    int N = scan.nextInt();
    int[] A = new int[N];
    for(int i=0; i<N; i++) {
      A[i] = scan.nextInt();
    }
    scan.close();

    Arrays.sort(A);

    int max = A[0] + K - A[N-1];
    for(int i=0; i<N-1; i++) {
      if(max < A[i+1] - A[i]) {
        max = A[i+1] - A[i];
      }
    }
    System.out.println(K - max);
  }
}
