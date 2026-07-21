import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    int K = scan.nextInt();
    int N = scan.nextInt();
    int[] ie = new int[N];
    for(int i = 0;i < N;i++){
      ie[i] = scan.nextInt();
    }
   int x,y,z,sa;
    z = 0;
    for(int i = 0;i < N - 1;i++){
       x = ie[i];
       y = ie[i+1];
       sa = y - x;
       if(sa > z){
         z = sa;
       }
    }
    x = ie[N-1];
    y = ie[0];
    sa = K - x + y;
    if(sa > z){
      z = sa;
    }
    System.out.println(K-z);
  }
}
