import java.util.Scanner;

public class Main {

	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) throws Exception {
		long[] branch = new long[16];
		branch[1] = 1;
		for (int i = 2; i < branch.length; ++i) {
			branch[i] = branch[i - 1] * 3 + 1;
		}
		while (sc.hasNext()) {
			int N = sc.nextInt();
			long ans = N;
			for (int i = 1; i < N - 1; ++i) {
				ans += 2 * branch[Math.min(i, N - 1 - i)];
			}
			System.out.println(ans);
		}
	}

}
