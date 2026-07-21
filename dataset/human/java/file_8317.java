import java.util.Scanner;

public class Main {
	static long lcm(long a, long b){
		return a * b / gcd(a, b);
	}
	static long gcd(long a, long b){
		if(a < b){
			return gcd(b, a);
		}
		long mod = a % b;
		if(mod == 0){
			return b;
		}else{
			return gcd(b, mod);
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextInt();
		long b = sc.nextInt();
		System.out.println(lcm(a, b));
	}
}
