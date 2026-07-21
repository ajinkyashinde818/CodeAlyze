import java.util.*;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int K = sc.nextInt();
    int N = sc.nextInt();
    int[] home = new int[N];
    int max = 0;
    for(int i=0; i<N; i++){
      home[i] = sc.nextInt();
      if(i>0)max = Math.max(max, Math.abs(home[i] - home[i-1]));
      else ;
    }
    max = Math.max(max, (home[0] + K - home[N-1]));
    System.out.print( K - max);
  }
}
