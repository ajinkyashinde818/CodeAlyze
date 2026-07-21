import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[] a = new int[N];
		int[] b = new int[N];
		int[] counter = new int[100003];

		for (int i = 0; i < N; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			++counter[a[i]];
			--counter[b[i] + 1];
		}
		int ans = 0;
		for (int i = 1; i < counter.length; ++i) {
			counter[i] += counter[i - 1];
			if (counter[i] + 1 >= i)
				ans = Math.max(ans, i - 1);
		}
		System.out.println(ans);

	}
}
