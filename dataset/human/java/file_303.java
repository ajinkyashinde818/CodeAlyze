import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int N = in.nextInt();
		long[] A = new long[N];
		long ans = 0;
		int count = 0;
		for (int i = 0; i < N; i++) {
			long num = in.nextLong();
			if (num < 0) {
				count++;
				num = num * -1;
			}
			A[i] = num;
			ans += A[i];
		}
		if (count % 2 != 0) {
			Arrays.sort(A);
			ans -= A[0] * 2;
		}
		System.out.println(ans);
		in.close();
	}
}
