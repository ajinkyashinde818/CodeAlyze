import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		sc.close();
		long mod = (long)Math.pow(10, 9) + 7;
		long[] cnt = new long[26];
		for(int i = 0; i < N; i++) {
			cnt[S.charAt(i) - 'a']++;
		}
		long ans = 1;
		for(long i : cnt) {
			ans = (i + 1) * ans % mod;
		}
		ans -= 1;
		ans %= mod;
		System.out.println(ans);
	}
}
