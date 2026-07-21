import java.util.*;

class Main {

	static Scanner sc = new Scanner(System.in);	

	public static long gcd(long a,long b) {
		if(b==0) return a;
		else if(a<b) return gcd(b,a);
		else return gcd(b,a%b);
	}
	
	public static void main(String[] args) {
		long A = sc.nextLong(),B = sc.nextLong();
		System.out.println((A*B)/gcd(A,B));
	}
}
