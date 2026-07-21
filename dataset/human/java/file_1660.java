import java.util.Scanner;

public class Main {

	static long MOD = 1000000007;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		char[] S = in.next().toCharArray();
		int[] alph = new int[26];
		for (int i = 0; i < S.length; i++) {
			alph[S[i] - 'a']++;
		}
		long ans = 1;
		for (int i = 0; i < alph.length; i++) {
			if (alph[i] > 0) {
				int num = alph[i] + 1;
				ans = ans * num % MOD;
			}
		}
		System.out.println(ans - 1);
		in.close();
	}
}
