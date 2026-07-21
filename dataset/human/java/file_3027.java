import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.next());
    int M = Integer.parseInt(sc.next());
    boolean[] f1 = new boolean[N+1];
    boolean[] f2 = new boolean[N+1];
    
    for(int i = 0; i < M; i++){
      int a = Integer.parseInt(sc.next());
      int b = Integer.parseInt(sc.next());
      if(a == 1){
        f1[b] = true;
      }
      if(b == 1){
        f1[a] = true;
      }
      if(a == N){
        f2[b] = true;
      }
      if(b == N){
        f2[a] = true;
      }
    }
    
    String ans = "IMPOSSIBLE";
    for(int i = 1; i <= N; i++){
      if(f1[i] && f2[i]){
        ans = "POSSIBLE";
        break;
      }
    }
    System.out.println(ans);
  }
}
