import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int M,N;
		Character[][] A = new Character [50][50];
		Character[][] B = new Character [50][50];
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		M = sc.nextInt();

		for(int i = 0; i < N; i++) {
			String str = sc.next();
			for(int j = 0; j < N; j++) {
				Character k = str.charAt(j);
				A[i][j] = k;
			}
		}

		for(int i = 0; i < M; i++) {
			String str = sc.next();
			for(int j = 0; j < M; j++) {
				Character k = str.charAt(j);
				B[i][j] = k;
			}
		}

		boolean exist = false;

		for(int i = 0; i < (N - M + 1); i++) {
			for(int j = 0; j < (N - M + 1); j++) {

				boolean match = true;

				for(int k = 0; k < M; k++) {
					for(int l = 0; l < M; l++) {
						if(B[k][l] != A[k + i][l + j]) {
							match = false;
							break;
						}
					}
					if(!match) {
						break;
					}
				}
				if(match) {
					exist = true;
					break;
				}
			}
			if(exist) {
				System.out.println("Yes");
				System.exit(0);
			}
		}

		System.out.println("No");

		sc.close();
	}
}
