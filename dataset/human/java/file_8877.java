import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		int t = Math.min(A, B);
		int cnt = 0;
		while (cnt < K) {
			if (A % t == 0 && B % t == 0)
				cnt++;
			t--;
		}

		System.out.println(t + 1);

		sc.close();
	}
}
