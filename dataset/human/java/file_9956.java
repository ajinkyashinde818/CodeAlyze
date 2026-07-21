import java.util.*;
public class Main {
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int X = sc.nextInt();
    int c[] = new int[N];
    int a[][] = new int[N][M];
    
    for(int i = 0 ; i < N ; ++i){
      c[i] = sc.nextInt();
      for(int j = 0 ; j < M ; ++j){
        a[i][j] = sc.nextInt();
      }
    }
    int ans = 1000000000;
    
    for(int i = 1 ; i < (1<<N) ; ++i){
      int k[] = new int[M];
      int l = 0;
      for(int j = 0 ; j < N ; ++j){
        if((1&(i>>j))==1){
          l += c[j];
          for(int o = 0 ; o < M ; ++o){
            k[o] += a[j][o];
          }
        }
      }
      for(int j = 0 ; j < M ; ++j){
        if(k[j] < X) break;
        if(j == M-1) ans = Math.min(ans,l);
      }
    }
    if(ans == 1000000000) System.out.println(-1);
    else System.out.println(ans);
    
  }
}
