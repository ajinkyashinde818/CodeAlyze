import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(System.in);
		while (true) {
			int n = sc.nextInt();
			if(n==0)break;
			int[][] s = new int[n + 1][n + 1];
			for (int i = 1; i < n + 1; i++) {
				char[] tmp = sc.next().toCharArray();
				for (int j = 1; j < n + 1; j++) {
					s[i][j] = tmp[j - 1] == '.' ? 1 : 0;
				}
			}
			int ans = 0;
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					if (s[i][j] == 0)
						continue;
					else {
						s[i][j] = Math.min(
								Math.min(s[i - 1][j], s[i - 1][j - 1]),
								s[i][j - 1]) + 1;
						ans = Math.max(s[i][j], ans);
					}
				}
			}
			System.out.println(ans);
		}
	}
}
