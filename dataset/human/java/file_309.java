import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[] A = new long[N];

		long sum = 0;
		long min = Long.MAX_VALUE / 2;
		int minusCnt = 0;

		for (int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
			sum += Math.abs(A[i]);
			min = Math.min(min, Math.abs(A[i]));
			if (A[i] < 0) {
				minusCnt++;
			}
		}
		sc.close();

		if (minusCnt % 2 == 0) {
			System.out.println(sum);
		} else {
			System.out.println(sum - (2 * min));
		}
	}
}
