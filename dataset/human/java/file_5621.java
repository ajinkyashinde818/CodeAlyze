import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();
    int S = sc.nextInt();
    
    int[] ans = new int[N];
    int B = S == 1000000000 ? S-1 : S+1;
    Arrays.fill(ans, B);
    for(int i = 0; i < K; i++){
      ans[i] = S;
    }
    for(int i = 0; i < N; i++){
      if(i != N-1){
        System.out.print(ans[i]+" ");
      }else{
		System.out.println(ans[i]);
      }
    }
  }
}
