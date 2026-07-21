import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int A[] = new int[N];
    int B[] = new int[N];
    int sum = 0;
    
    for(int i=0; i<N; i++) {
      A[i] = sc.nextInt();
    }
    B[0] = A[0] + K - A[N-1];
    for(int j=1; j<N; j++) {
      B[j] = A[j] - A[j-1];
    }
    Arrays.sort(B);
    for(int k=0; k<N-1; k++) {
      sum += B[k];
    }
    System.out.println(sum);
  }
}
