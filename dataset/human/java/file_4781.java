import java.util.*;
public class Main{   
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      long n = sc.nextLong();
      if(n%2==1){
        System.out.println(0);
        return;
      }
      long x = n/2;
      long sum = 0;
      while(x>0){
        sum+=x/5;
        x/=5;
      }
      System.out.println(sum);
    }
    public static int lcm(int x, int y){
      return x*y/gcd(x,y);
    }
    public static int gcd(int x, int y){
      if(x < y)return gcd(y,x);
      if(y==0)return x;
      return gcd(y,x%y);
    }
}
class Pair{
    int a,b;

    Pair(int a, int b){
      this.a = a;
      this.b = b;
    }
}
