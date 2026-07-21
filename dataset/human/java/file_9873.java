import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int X = sc.nextInt();
		int C[] = new int[N];
		int A[][] = new int[N][M];
		for(int i = 0; i < N; i++) {
			C[i] = sc.nextInt();
			for(int j = 0; j < M; j++) {
				A[i][j] = sc.nextInt();
			}
		}
		
		int ans = Integer.MAX_VALUE;
		out : for (int i = 0; i < (Math.pow(2, N)); i++) {
			int temp = 0;
			int a[] = new int[M];
			for (int j = 0; j < N; j++) {
				if ((1&i>>j) == 1) {
					temp += C[j];
					for(int k = 0; k < M; k++) {
						a[k] += A[j][k];
					}
				}
			}
			for(int k = 0; k < M; k++) {
				if(a[k] < X) {
					continue out;
				}
			}
			ans = Math.min(ans, temp);
		}
		if(ans == Integer.MAX_VALUE) {
			System.out.println(-1);
		} else {
			System.out.println(ans);
		}
	}
}
