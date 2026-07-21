import java.util.Scanner;

public class Main {
	public static void main(String[] args)  {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		int k = 0;
		int ans = 0;
		for(int i = 0; i <= K; i++) {
			for(int j = 0; j <= K; j++) {
				k = S - i - j;
				if((k <= K) && (k >= 0)) {
					ans++;
				}
			}
		}
		System.out.println(ans);
		}
}
