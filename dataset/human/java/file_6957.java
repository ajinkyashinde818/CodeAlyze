import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int[] A = new int[N];

    for (int i = 0; i < N; i++) {
      A[i] = sc.nextInt();
    }
    int max = 0 ;

    for (int i = 0; i < N -1 ; i++) {
      int tmp = (A[i +1] - A[i]);
      // System.out.println(A[i]); 
      if(tmp >= max){
        max = tmp;
        }
      // System.out.println(max); 
      }
    int tmp2 = (K - A[N-1]) + A[0];
    if(tmp2 > max){
      max = tmp2;
    }
    System.out.println(K - max);   
    return;
  }
}
