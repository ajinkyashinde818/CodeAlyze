import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();
		long ans = 0;
		long x = a*b;
		if(a<b) {
			long tmp = a;
			a = b;
			b = tmp;
		}
		long r = a%b;
		while(r!=0) {
			a = b;
			b = r;
			r = a % b;
		}
		ans = x/b;
		System.out.println(ans);
	}
}
