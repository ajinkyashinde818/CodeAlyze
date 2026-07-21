import java.util.*;
public class Main {
  public static void main(String[] args){
    
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] a = new int[M];
    int[] b = new int[M];
    boolean[] at = new boolean[200001];
    boolean[] nt = new boolean[200001];
    for(int i = 0 ; i < M; i++){
      a[i] = sc.nextInt();
      b[i] = sc.nextInt();
      if(a[i]==1){
        at[b[i]]=true;
      }
      if(b[i]==N){
        nt[a[i]]=true;
      }
    }
    
    if(M < 2){
      System.out.println("IMPOSSIBLE");
      return;
    }
    
    for(int i = 0 ; i < 200001; i++){
        if(at[i] && nt[i]){
          System.out.println("POSSIBLE");
          return; 
        }
    }
    System.out.println("IMPOSSIBLE");
  }
}
