import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    long a = Integer.parseInt(sc.next());
    long b = Integer.parseInt(sc.next());
	long tmp;
    long g = 1;
    long ans = 0;
    
    if (a < b) {
      tmp = a;
      a = b;
      b = tmp;
    }
    g = gcd(a, b);
    
    ans = a*b/g;
    
    System.out.println(ans);
    
  }
  
  public static long gcd(long a, long b) {
    if (b == 0) {
      return a;
    } else {
      return gcd(b,a%b);
    }
  }
}
