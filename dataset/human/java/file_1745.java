import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		long mod = 1000000007;
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		String S = sc.nextLine();
		int[] cnt = new int[27];
		for(int i = 0; i < S.length(); i++) {
			cnt [S.charAt(i)-'a'] ++;
		}
		long ans = 1;
		long tmp;
		for(int i = 0; i < 27; i++) {
			ans += ans*cnt[i];
			ans%=mod;
		}
		--ans;
		System.out.println(ans);
	}

}
