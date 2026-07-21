import java.util.*;

public class Main{
  public static void main(String[]args){
    Scanner sc = new Scanner(System.in);
    int N = Integer.parseInt(sc.nextLine());
    int minus = 0;
    long min = 1000000000;
    long ans = 0;
    for(int i = 0; i < N; i++){
      long n = Long.parseLong(sc.next());
      if(n < 0){
        minus++;
      }
      ans += Math.abs(n);
      if(Math.abs(n) < min){
        min = Math.abs(n);
      }
    }
    if(minus % 2 == 1){
      ans -= min*2;
    }
    System.out.println(ans);
  }
}
