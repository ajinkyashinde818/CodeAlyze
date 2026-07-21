import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int minusCount = 0;
    long sum = 0;
    int min = 1001001001;
    for (int i = 0; i < N; i++) {
      int A = sc.nextInt();
      sum += Math.abs(A);
      min = Math.min(min, Math.abs(A));
      if (A < 0) {
        minusCount++;
      }
    }
    System.out.println(minusCount%2 == 0 ? sum : sum-2*min);
  }    
}
