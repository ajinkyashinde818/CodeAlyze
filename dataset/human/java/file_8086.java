import java.io.InputStream;
import java.util.Scanner;
// https://atcoder.jp/contests/abs/tasks/abc081_b
public class Main {
  public static void main(String[] args){
    System.out.println(new Main().excute(System.in)); 
  }

  public String excute(InputStream f) {
    Scanner scan = new Scanner(f);
    long a = scan.nextLong();
    long b = scan.nextLong();
    
    return "" + ((a * b) / gcd(a, b));
  }

  private long gcd(long a, long b) {
    if(a < b) {
      return gcd(b, a);
    }
    if(b == 0) {
      return a;
    }
    return gcd(b, a % b);
  }

}
