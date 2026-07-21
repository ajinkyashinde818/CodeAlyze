import java.util.*;
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int M = sc.nextInt();
    int[] a = new int[M];
    int[] b = new int[M]; 
    boolean[] check1 = new boolean[N];
    boolean[] check2 = new boolean[N];
    List<Integer> list = new ArrayList<>();
    for(int i=0;i<M;i++){
      a[i] = sc.nextInt()-1;
      b[i] = sc.nextInt()-1;
      if(a[i]==0){
        check1[b[i]]=true;
      }
      if(b[i]==N-1){
        check2[a[i]]=true;
      }
    }
    String ans = "IMPOSSIBLE";
    for(int i=0;i<N;i++){
      if(check1[i] && check2[i]){
        ans = "POSSIBLE";
      }
    }
    System.out.println(ans);
  }
}
