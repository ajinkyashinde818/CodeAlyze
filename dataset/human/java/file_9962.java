import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int[] C = new int[N];
		int[][] A = new int[N][M];
		for (int i = 0; i < N; i++) {
			C[i] = sc.nextInt();
			for (int j = 0; j < M; j++) {
				A[i][j] = sc.nextInt();	
			}
		}
		int ans = 1 << 25;
		int[] r = new int[M];
		L: for (int S = 1; S < 1 << N; S++) {
			int csum = 0;
			Arrays.fill(r, 0);
			for (int i = 0; i < N; i++) {
				if (((S >> i) & 1) > 0) {
					csum += C[i];
				}
			}
			if (csum >= ans) continue;
			for (int i = 0; i < N; i++) {
				if (((S >> i) & 1) > 0) {
					for (int j = 0; j < M; j++) {
						r[j] += A[i][j];
					}
				}
			}
			for (int j = 0; j < M; j++) {
				if (r[j] < X) {
					continue L;
				}
			}
			ans = csum;
		}
		System.out.println(ans < 1 << 25? ans : -1);
	}
}
