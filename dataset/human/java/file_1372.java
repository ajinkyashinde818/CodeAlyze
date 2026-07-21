import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int M = sc.nextInt();
		char[][] A = new char[N][N];
		char[][] B = new char[M][M];
		for (int i=0; i<N; i++) {
			char[] t = sc.next().toCharArray();
			for (int j=0; j<N; j++) {
				A[i][j] = t[j];
			}
		}
		for (int i=0; i<M; i++) {
			char[] t = sc.next().toCharArray();
			for (int j=0; j<M; j++) {
				B[i][j] = t[j];
			}
		}
		boolean exist = false;
		for (int i=0; i<N; i++) {
			for (int j=0; j<N; j++) {
				if ( j+M-1>=N || i+M-1>=N ) continue;
				boolean flg = true;
				for (int k=0; k<M; k++) {
					for (int l=0; l<M; l++) {
						if ( A[i+k][j+l] != B[k][l] ) flg = false;
					}
				}
				if (flg) exist = true;
			}
		}
		if (exist) System.out.println("Yes");
		else System.out.println("No");
	}
}
