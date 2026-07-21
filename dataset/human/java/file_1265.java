import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		long[] a = new long[N];
		long[] sum = new long[N];
		
		for(int i = 0; i < N; i++) {
			a[i] = sc.nextLong();
			if(i == 0) {
				sum[i] = a[i];
			} else {
				sum[i] = sum[i - 1] + a[i];
			}
		}
		
		long min = Math.abs(sum[N - 1] - sum[0] - sum[0]);
		
		for(int i = 1; i < N - 1; i++) {
			long x = sum[i];
			long y = sum[N - 1] - sum[i];
			min = Math.min(min, Math.abs(x - y));
		}
		System.out.println(min);
	}
}
