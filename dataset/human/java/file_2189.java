import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	List<Integer> prime = new ArrayList<>();
	int tri[] = { 0, 1, 3, 6, 10, 15, 21, 28, 36, 45 };

	public void main(Scanner sc) {
		prime.add(2);
		for (int i = 3; i <= 1000000; i += 2) {
			boolean flag = true;
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0) {
					flag = false;
				}
			}

			if (flag) {
				prime.add(i);
			}
		}

		long n = sc.nextLong();
		int ans = 0;
		for (int p : prime) {
			int cnt = 0;
			if (n % p == 0) {
				while (n % p == 0) {
					n /= p;
					cnt++;
				}
			}

			for (int i = 0; i < 10; i++) {
				if (tri[i] > cnt) {
					ans += (i - 1);
					break;
				}
			}
		}

		if (n != 1) {
			ans++;
		}

		System.out.println(ans);
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		new Main().main(sc);
	}
}
