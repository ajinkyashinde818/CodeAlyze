import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long[] ruisekiWA = new long[n];
		ruisekiWA[0] = sc.nextLong();
		for(int i = 1; i < n; i++) {
			ruisekiWA[i] = sc.nextLong()+ruisekiWA[i-1];
		}
		long ans = Long.MAX_VALUE;
		for(int i = 0; i < n-1; i++) {
			long x = ruisekiWA[i];
			long y = ruisekiWA[n-1] - x;
			//System.out.println("一人目："+ruisekiWA[i]);
			//System.out.println("二人目："+ruisekiWA);
			ans = Math.min(ans, Math.abs(x-y));
		}
		System.out.println(ans);
	}
}
