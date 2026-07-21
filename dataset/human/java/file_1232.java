import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long[]a = new long[N];
		long sum = 0;
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			sum += a[i];
		}
		sc.close();
		long[]b = new long[N + 1];
		for(int i = 1; i <= N; i++) {
			b[i] = b[i-1] + a[i - 1];
		}
		long min = Long.MAX_VALUE;
		for(int i = 1; i <= N - 1; i++) {
			long x = b[i];
			long y = sum - b[i];
			min = Math.min(min, Math.abs(x - y));
		}
		System.out.println(min);
	}
}
