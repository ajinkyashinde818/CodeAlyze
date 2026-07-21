import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();

		int max = 0;

		int first = sc.nextInt();

		int prev = first;
		int now = 0;

		for (int i = 1; i < n; i++) {
			now = sc.nextInt();
			max = Math.max(max, now - prev);
			prev = now;
		}
		sc.close();

		max = Math.max(max, k - now + first);

		print(k - max);
	}

	public static void print(Object obj) {
		System.out.println(obj);
	}

}
