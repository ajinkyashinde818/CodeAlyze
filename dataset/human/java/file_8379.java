import java.util.*;
public class Main{
  public static void main(String[] args) {
    Scanner sc=new Scanner(System.in);
    long a=sc.nextInt();
    long b=sc.nextInt();
    System.out.println(a*b/gcd(a,b));
  }
  public static long gcd(long x,long y){
    if(y==0) return x;
    else return gcd(y,x%y);
  }
}
