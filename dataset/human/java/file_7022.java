import java.util.*;
 
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int A[] = new int[N+1];
    for(int i = 0; i<N; i++){
      A[i]=sc.nextInt();
    }
    int ans = 0;
    A[N]=A[0]+K;
    for(int i = 0; i<N; i++){
      ans=Math.max(ans, A[i+1]-A[i]);
    }
    System.out.println(K-ans);
  }
}
