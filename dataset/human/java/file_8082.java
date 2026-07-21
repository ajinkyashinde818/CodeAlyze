import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A=sc.nextLong(),B=sc.nextLong();
		long ans=A/gcd(A,B)*B;
		System.out.println(ans);


	}

	public static long gcd(long a,long b) {
		if(a<b) {
			return gcd(b,a);
		}
		if(b==0) {
			return a;
		}
		return gcd(b,a%b);
	}
}
