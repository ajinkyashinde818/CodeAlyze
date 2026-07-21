import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    int[] ans = new int[101];
    for(int i=1; i<=100; i++){
      if( a%i == 0) ans[i]++;
      if( b%i == 0) ans[i]++;
    }
    int kb = 0;
    for(int i=100; i>=1; i--){
      if( ans[i] == 2 ) {
        ++kb;
        if( kb == k){
          System.out.println(i);
          System.exit(0);
        }
      }
    }
  }
}
