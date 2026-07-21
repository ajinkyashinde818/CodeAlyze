import java.util.*;
class Main {
  public static void main (String[] args) throws Exception {
    
    Scanner sc=new Scanner(System.in);
    
    long a = sc.nextLong();//解毒まずい
    long b = sc.nextLong();//解毒美味しい
    long c = sc.nextLong();//有毒美味しい
    
    long ans=0;
    
    if(a+b>=c)ans = b+c;
    else ans = a+b+1+b;
    
    System.out.println(ans);

  }
}
