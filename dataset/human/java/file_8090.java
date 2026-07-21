import java.util.Scanner;


public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {
		
			long a = sc.nextLong();
			long b = sc.nextLong();
			
			long gcd = gcd(a, b);
			
			long afactor = a / gcd;
			long bfactor = b / gcd;
			
			System.out.println(gcd * afactor * bfactor);

		}
	}
	
	public static long gcd(long a, long b) {
		if ( a > b ) {
			return gcd(b, a);
		}
		
		if ( b % a == 0) {
			return a;
		}
		else {
			return gcd(a, b % a);
		}
	}

}
