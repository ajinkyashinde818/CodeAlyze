import java.util.*;
import java.math.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    long A[] = new long[N];
    for (int i=0; i<N; i++) {
      A[i] = sc.nextLong();
    }
    long maxhu = -1_000_000_001;
    long minsei = 1_000_000_001;
    int counthu = 0;
    long out = 0;
    for (int i=0; i<N; i++) {
      if(A[i] < 0){
        counthu++;
      }
      if(A[i] < 0 && maxhu < A[i]){
        maxhu = A[i];
      } else if (A[i] >= 0 && minsei > A[i]){
        minsei = A[i];
      }
    }
    for (int i=0; i<N; i++) {
      if(A[i] < 0){
        out -= A[i];
      } else {
        out += A[i];
      }
    }
    if(counthu%2 == 1){
      out -= 2*Math.min(-maxhu, minsei);
    }
    System.out.println(out);
  }
}
