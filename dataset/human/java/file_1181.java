import java.util.Scanner;
public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		
		long A = 0;
		long B = 0;
		long[] map = new long[N];
		for (int i = 0; i < N; i++) {
			map[i] = sc.nextLong();
			A += map[i];
		}
		
		long ans = Long.MAX_VALUE;
		for (int i = N - 1; i > 0; i--) {
			B += map[i];
			A -= map[i];
			long abs = Math.abs(A - B);
			ans = Math.min(abs, ans);
		}
		
		System.out.println(ans);
	}
}
