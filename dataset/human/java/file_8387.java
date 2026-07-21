import java.util.*;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    System.out.println(lcm(a,b)); 
  }
    //最大公約数・最小公倍数（セットで使う）
static long gcd (long a, long b) {return b>0?gcd(b,a%b):a;}
static long lcm (long a, long b) {return a*b/gcd(a,b);}
  

  
}
