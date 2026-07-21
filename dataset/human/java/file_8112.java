import java.util.*;

class Main{
	static long lcm(long a, long b) {
		return a/gcd(a,b)*b;
	}
	static long gcd(long a, long b) {
		return a%b==0 ? b : gcd(b, a % b);
	}
	public static void main(String[] $){
		Scanner s=new Scanner(System.in);
		int n=s.nextInt(),m=s.nextInt();
		System.out.println(lcm(n,m));
	}
}
