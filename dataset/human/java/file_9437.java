import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int[][] D = new int[N][2];

		for (int i = 0; i < D.length; i++) {
			D[i][0] = sc.nextInt();
			D[i][1] = sc.nextInt();
		}

		for (int i = 0; i < D.length - 2; i++) {
			if (D[i][0] == D[i][1] && D[i + 1][0] == D[i + 1][1] && D[i + 2][0] == D[i + 2][1]) {
				System.out.print("Yes");
				return;
			}
		}

		System.out.print("No");
	}

}
