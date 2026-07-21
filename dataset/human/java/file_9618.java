import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] d = new int[n][2];
		for (int i = 0; i < n; i++) {
			d[i][0] = sc.nextInt();
			d[i][1] = sc.nextInt();
		}
		sc.close();

		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (d[i][0] == d[i][1]) {
				cnt++;
				if (cnt == 3) {
					System.out.println("Yes");
					return;
				}
			} else {
				cnt = 0;
			}
		}
		System.out.println("No");
	}
}
