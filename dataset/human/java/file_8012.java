import java.util.HashMap;
import java.util.Scanner;
class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    sc.close();
    System.out.println((long) a * b / gcd(a,b));
  }
  public static int gcd(int a, int b){
    if(a % b == 0){
      return b;
    }
    return gcd(b, a%b);
  }
}
