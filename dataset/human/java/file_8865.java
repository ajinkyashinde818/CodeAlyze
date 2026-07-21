import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		int ans = 0;
		int cnt = 0;
		for (int i = Math.min(A, B); i > 0 ; i--) {
			if (A % i == 0 && B % i == 0) {
				ans = i;
				cnt++;
				if (cnt == K) break;
			}
		}

		System.out.println(ans);
	}

}
