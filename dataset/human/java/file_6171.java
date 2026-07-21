import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		long cnt = 0;
		int K = input.nextInt();
		int S = input.nextInt();
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= K; j++) {
				int k = S-i-j;
				if (k>=0&&k<=K) cnt++;
			}
		}
		System.out.println(cnt);
	}
	public static boolean Three(int a, int b, int c) {
		if (a!=b&&b!=c&&c!=a) return true;
		return false;
	}
	public static boolean One(int a, int b, int c) {
		if (a==b&&b==c&&c==a) return true;
		return false;
	}
}
