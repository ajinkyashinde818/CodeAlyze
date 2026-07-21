import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    long N = sc.nextLong();
    long ans = 0;
    if(N%2 == 0){
      N /= 2;
      while(N>0){
        ans += N/5;
        N /= 5;
      }
    }
    System.out.println(ans);
  }
}
