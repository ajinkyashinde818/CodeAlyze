import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int M = scanner.nextInt();
		int X = scanner.nextInt();
		int P = (int)Math.pow(2, N);
		long[] tC = new long[P];
		long[][] Xs = new long[P][M];
		for(int i = 0; i < N; i++) {
			int C = scanner.nextInt();
			int[] A = new int[M];
			int mask = (int)Math.pow(2, i);
			for(int j = 0; j < M; j++) {
				A[j] = scanner.nextInt();
			}
			for(int j = 0; j < P; j++) {
				if((j & mask) > 0) {
					tC[j] += C;
					for(int k = 0; k < M; k++) Xs[j][k] += A[k];
				}
			}
		}
		long answer = Long.MAX_VALUE;
		boolean found = false;
		for(int i = 0; i < P; i++) {
			long sum = tC[i];
			if(sum > answer) continue;
			boolean isPossible = true;
			for(int j = 0; j < M; j++) {
				if(Xs[i][j] < X) {
					isPossible = false;
					break;
				}
			}
			if (isPossible) {
				answer = sum;
				found = true;
			}
		}
		System.out.println(found ? answer : -1);
	}
}
