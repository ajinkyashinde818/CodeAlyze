import java.util.*;
class Main {
  
static Long gcd (Long a, Long b) {return b>0?gcd(b,a%b):a;}
static Long lcm (Long a, Long b) {return a*b/gcd(a,b);}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
      
      	Long a = sc.nextLong();
      	Long b = sc.nextLong();
      	Long ans = lcm(a,b); 	
      	
      System.out.println(ans);
		}
	}
