import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int N = reader.nextInt();
		long ans = Long.MAX_VALUE;
		long[] arr = new long[N+1];
		for (int i = 0; i < N; i++) {
			arr[i] += reader.nextLong();
			arr[i+1] = arr[i];
		}
		long last = arr[N-1];
		for (int i = 0; i < N-1; i++) {
			long gap = Math.abs(arr[i]-(last-arr[i]));
			ans = Math.min(ans, gap);
		}


		System.out.println(ans);
		reader.close();

	}
}
