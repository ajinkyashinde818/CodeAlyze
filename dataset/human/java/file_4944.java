import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		long N = scn.nextLong();
		long ans = 0;
		if(N%2==1) {
			System.out.println(0);
			return;
		}
		long n = N;
		ans += N/10;
		n = N/10;
				while(n>0) {
					ans += n/5;
					n /=5;
				}
		System.out.println(ans);
	}

}
