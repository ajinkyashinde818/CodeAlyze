import java.util.*;

class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
      	long a = sc.nextLong();
      	long b = sc.nextLong(); 
      
      	System.out.println(lcm(a, b));
    }
  	
  	public static long lcm(long a, long b) {
    	long g = gcd(a, b);
      	return g * (a / g) * (b / g);
    }
  
  	public static long gcd(long a, long b) {
    	if (a > b) {
        	long tmp = a;
          	a = b;
          	b = tmp;
        }
      	if (a == 0) { return b; }
      	return gcd(b % a, a);
    }
}
