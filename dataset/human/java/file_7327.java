import java.util.*;
public class Main{   
    public static void main(String[] args){
      Scanner sc = new Scanner(System.in);
      String s = sc.next();
      if(s.replaceAll("eraser","").replaceAll("erase","").replaceAll("dreamer","").replaceAll("dream","").equals(""))System.out.println("YES");
      else System.out.println("NO");
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
