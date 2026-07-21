import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			int n = scanner.nextInt();
			if (n == 0)
				break;
			int max = 0;
			int[][] map = new int[n + 1][n + 1];
			for (int i = 1; i < n + 1; i++) {
				String line = scanner.next();
				for (int j = 1; j < n + 1; j++) {
					if (line.charAt(j - 1) == '*') {
						map[i][j] = 0;
					} else {
						int num = Integer.MAX_VALUE;
						num = Math
								.min(num, Math.min(map[i - 1][j - 1],
										Math.min(map[i - 1][j], map[i][j - 1])));
						map[i][j] = num + 1;
						max = Math.max(max, map[i][j]);
					}
				}
			}
			System.out.println(max);
		}
	}

}
