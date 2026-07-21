import java.util.Scanner;


public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    System.out.println(lcm(a,b));
  }
  
  static long gcd(long a, long b) 

    { 

        if (a == 0) 

            return b; 

              

        return gcd(b % a, a); 

    } 

      

    // function to calculate lcm of 

    // two numbers. 

    static long lcm(long a, long b) 

    { 

        return (a * b) / gcd(a, b); 

    } 

}
