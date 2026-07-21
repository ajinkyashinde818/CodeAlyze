import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		long A = scan.nextLong();
		long B = scan.nextLong();
		long re = gcd(A,B);

		System.out.println(lcm(A,B,re)) ;

		scan.close();

	}

	public static long gcd(long a,long b) {

		for(long i=a;i>0;i--) {
			if(a%i == 0 && b%i == 0) {
				return i;
			}
		}
		return 1;
	}

	public static long lcm(long a,long b, long gcd) {

		return a*b/gcd;
	}

}
