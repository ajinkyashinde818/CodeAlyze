import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextInt();
		long B = sc.nextInt();
		System.out.println(lcm(A,B));
	}
	
	static long gcd(long a,long b) {
		if(a<b) {
			return gcd(b,a);
		}else if(b==0) {
			return a;
		}else {
			return gcd(b,a%b);
		}
	}
	
	static long lcm(long a,long b) {
		return a*b/gcd(a,b);
	}

}
