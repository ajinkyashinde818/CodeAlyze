import java.util.*;

public class Main{
  static int gcd (int a, int b) {return b>0?gcd(b,a%b):a;}

  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int a = sc.nextInt();
    int b = sc.nextInt();
    int gg = gcd(a,b);//最大公約数
    int a_in = a/gg;
    int b_in = b/gg;
    long ans = (long)a * (long)b_in;

    System.out.println(ans);

  }
}
