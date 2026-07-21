import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt(), m = s.nextInt();
		long x = s.nextLong();
		long[] c = new long[n];
		long[][] a = new long[n][m];
		for(int i = 0; i < n; i++) {
			c[i] = s.nextLong();
			for(int j = 0; j < m; j++) {
				a[i][j] = s.nextLong();
			}
		}
		long ans = -1;
		for(int num = 1; num < Math.pow(2, n); num++) {
			int[] arr = new int[m];
			long temp = 0;
			for(int i = 0; i < n; i++) {
				if(((num >> i) & 1) == 1) {
					for(int j = 0; j < m; j++) {
						arr[j] += a[i][j];
					}
					temp += c[i];
				}
			}
			boolean possible = true;
			for(int i = 0; i < m; i++) {
				if(arr[i] < x) {
					possible = false;
				}
			}
			if(possible) {
				if(ans == -1) {
					ans = temp;
				} else {
					ans = Math.min(ans, temp);
				}
			}
		}
		System.out.println(ans);

	}

}
