import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N  = sc.nextInt();
		int M  = sc.nextInt();
		
		String[] A = new String[N];
		String[] B = new String[M];
		
		for(int i = 0; i < N; i++) {
			A[i] = sc.next();
		}
		
		for(int i = 0; i < M; i++) {
			B[i] = sc.next();
		}
		
		for(int i = 0; i <= N - M; i++) {
			for(int j = 0; j <= N - M; j++) {
				for(int k = 0; k < M; k++) {
					String a = A[k + i].substring(j, j + M);
					if(!a.equals(B[k])) {
						break;
					}
					if(k == M - 1) {
						System.out.println("Yes");
						return;
					}
				}
			}
		}
		System.out.println("No");
	}
}
