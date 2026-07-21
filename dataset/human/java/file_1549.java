import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);

	public static void main(String[] args) {
		int N = sc.nextInt();
		int M = sc.nextInt();
		String[] A = new String[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.next();
		}
		String[] B = new String[M];
		for (int i = 0; i < M; i++) {
			B[i] = sc.next();
		}
		
		for (int i = 0; i <= N - M; i++) {
			for (int j = 0; j <= N - M; j++) {
				boolean hit = true;
				if (A[i].substring(j, j + M).equals(B[0])) {
					for (int k = 1; k < M; k++) {
						if (!A[i + k].substring(j, j + M).equals(B[k])) {
							hit = false;
							break;
						}
					}
				} else {
					hit = false;
					continue;
				}
				
				if (hit) {
					System.out.println("Yes");
					return;
				}
			}
		}
		
		System.out.println("No");
	}
}
