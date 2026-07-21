import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (true) {
			int n = sc.nextInt();
			if (n == 0)
				break;
			String[] f = new String[n];
			int[][] fi = new int[n][n];
			for (int i = 0; i < n; i++)
				f[i] = sc.next();
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++) {
					if (f[i].charAt(j) == '.')
						fi[i][j] = 1;
					else if (f[i].charAt(j) == '*')
						fi[i][j] = 0;
				}
			for (int i = 1; i < n; i++)
				for (int j = 1; j < n; j++)
					if (fi[i][j] == 1 && fi[i - 1][j] != 0 && fi[i][j - 1] != 0
							&& fi[i - 1][j - 1] != 0)
						fi[i][j] = Math.min(fi[i - 1][j - 1],
								Math.min(fi[i - 1][j], fi[i][j - 1])) + 1;
			int max = 0;
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					max = Math.max(max, fi[i][j]);
			System.out.println(max);
		}
		sc.close();
	}
}
