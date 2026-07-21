import java.util.*;
public class Main{
  public static void main(String[] args)
  {
    Scanner input = new Scanner(System.in);
    long a = input.nextLong();
    long b = input.nextLong();
    System.out.println(lcm(a,b));
  }



static long gcd(long a, long b) 
    { 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
    } 
      
    // method to return LCM of two numbers 
    static long lcm(long a, long b) 
    { 
        return (a*b)/gcd(a, b); 
    } 
}
