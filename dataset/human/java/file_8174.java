import java.util.Scanner;

public class Main {

	private static long gcd(long m, long n) {
	    if(m < n) return gcd(n, m);
	    if(n == 0) return m;
	    return gcd(n, m % n);
	}

	private static long lcm(long m, long n) {
	    return m * n / gcd(m, n);
	}

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		long A = sc.nextInt();
		long B = sc.nextInt();

		sc.close();
		System.out.println(lcm(A,B));
	}


}
