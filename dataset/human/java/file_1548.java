import java.util.Scanner;

public class Main {
	char[][] a;
	char[][] b;
	void run() {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		int count = 0;
		a = new char[N][N];
		b = new char[M][M];
		for(int i = 0; i < N; i++) {
			String tmp = sc.next();
			a[i] = tmp.toCharArray();
		}
		for(int i = 0; i < M; i++) {
			String tmp = sc.next();
			b[i] = tmp.toCharArray();
		}
		for(int i = 0; i <= N - M; i++) {
			for(int j = 0; j <= N - M; j++) {
				for(int k = 0; k < M; k++) {
					for(int l = 0; l < M; l++) {
						if(b[k][l] == a[i+k][j+l]) {
							count++;
						}
					}
					if(count == M * M) {
						System.out.println("Yes");
						sc.close();
						return;
					}
				}
				count = 0;
			}
		}
		System.out.println("No");
		sc.close();
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
