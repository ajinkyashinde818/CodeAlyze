import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		var n = sc.nextInt();
		var m = sc.nextInt();
		var x = sc.nextInt();
		var c = new int[n];
		var a = new int[n][m];
		for (var i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for (var j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		sc.close();

		var min = Integer.MAX_VALUE;
		for (int i = 0; i < (int) Math.pow(2, n); i++) {
			var sum = 0;
			var asum = new int[m];
			for (int j = 0; j < n; j++) {
				if( ((i % (int) Math.pow(2, j + 1)) / ((int) Math.pow(2, j))) != 0) {
					sum += c[j];
					for (int k = 0; k < m; k++) {
						asum[k] += a[j][k];
					}
				}
			}
			if (Arrays.stream(asum).allMatch(aa -> aa >= x)) {
				min = Math.min(min, sum);
			}
		}
		System.out.println(min == Integer.MAX_VALUE ? -1 : min);
	}
}
