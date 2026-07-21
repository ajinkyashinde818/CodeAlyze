import java.util.*;

public class Main{
  public static void main(String[] args){
    Scanner scan = new Scanner(System.in);
    long n = scan.nextLong();
    if (n%2 == 1){
      System.out.println(0);
      return;
    }
    long target = fast(n);
    long r = 5;
    long sum = 0;
    n = (long) n/2;
    while (r <= target){
      sum += (long) n/r;
      r*=5;
    }
    System.out.println(sum);
  }

  static long fast(long n){
    long ret = 1;
    while (ret <= n){
      ret *= 5;
    }
    return (long) ret/5;
  }

}
