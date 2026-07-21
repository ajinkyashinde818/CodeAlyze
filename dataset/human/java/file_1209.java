import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		new Main().execute();
	}

	public void execute() {
		Scanner sc = new Scanner(System.in);
		final int N = sc.nextInt();
		long diff = Long.MAX_VALUE;
		long[] sum = new long[N];

		for (int i = 0; i < N; i++) {
			int ai = sc.nextInt();
			if (i == 0) {
				sum[i] = ai;
			} else {
				sum[i] = sum[i - 1] + ai;
			}
		}
		final long total = sum[N - 1];

		for (int i = 0; i < N - 1; i++) {
			long snk = sum[i];
			long arai = total - snk;
			diff = Math.min(diff, Math.abs(snk - arai));
		}

		System.out.println(diff);
		sc.close();
	}

}
