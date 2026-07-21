import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
	 	Scanner scanner = new Scanner(System.in);
	 	int K = scanner.nextInt();
	 	int N = scanner.nextInt();
	 	int[] A = new int[N];
	 	int[] D = new int[N];
	 	for (int i = 0; i < N; i++) {
	 		A[i] = scanner.nextInt();
	 	}
	 	for (int i = 0; i < N-1; i++) {
	 		D[i] = A[i+1] - A[i];
	 	}
	 	D[N-1] = A[0] + K - A[N-1];

	 	/*
	 	for (int i = 0; i < N; i++) {
 			System.out.println(D[i]);
 		}*/

	 	int max=D[0];
        for (int j = 1; j < N; j ++) {
            max = Math.max(max, D[j]);//[4]
        }
        //System.out.println(max);
        System.out.println(K - max);
	}
}
