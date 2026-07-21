import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	public void run() {
		Scanner sc = new Scanner(System.in);
		long a=sc.nextLong();
		long b=sc.nextLong();
		long ans = lcm(a,b);
		System.out.println(ans);
		sc.close();
	}

	public long gcd(long a, long b) {
		if(b==0) {
			return a;
		}
		long ans = gcd(b, a%b);
		return ans;
	}
	public long lcm(long a, long b) {
		long g = gcd(a,b);
		return a*b/g;
	}
}
