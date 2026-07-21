import java.util.*;
public class Main {

  public static void main(String[] args) { 
      Scanner sc = new Scanner(System.in);
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt();
      int gcd = gcd(a, b);

      for(int i = gcd; i >= 1; i--) {
        if(a % i == 0 && b % i == 0) {
          k--;
          if(k == 0) {
            System.out.println(i);
            return;
          }
        }
      }
  }

  private static int gcd(int a, int b) {
    if(b == 0)
      return a;
    return gcd(b, a % b);
  }
}
