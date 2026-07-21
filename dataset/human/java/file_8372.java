import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    int a = scan.nextInt();
    int b = scan.nextInt();

    long p = ((long)a*(long)b);
    long ans = p/gcd(a,b);
    System.out.println(ans);
  }

  public static int gcd(int a, int b){
      if( a == 0){
          return b;
      }
      return gcd(b%a,a);
  }
}
