import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		Long a1 = Long.parseLong(sc.next());
		Long a2 = Long.parseLong(sc.next());
		
		Long ans = lcm(a1,a2);
		
		System.out.println(ans);;
	}



	static Long gcd (Long a, Long b) {return b>0?gcd(b,a%b):a;}
	static Long lcm (Long a, Long b) {return a*b/gcd(a,b);}

}
