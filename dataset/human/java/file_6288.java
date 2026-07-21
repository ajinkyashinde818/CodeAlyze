import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		int ans = 0;
		for (int i = 0; i <= K; i++) {
			for (int j = 0; j <= K; j++) {
				int Z = S - i - j;
				if (Z >= 0 && Z <= K) {
					ans++;
				}
			}
		}
		System.out.println(ans);
		sc.close();
	}
}
