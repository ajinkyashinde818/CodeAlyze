import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int[][] matrix = new int[n][63];
		for (int i = 0; i < n; i++) {
		    matrix[i][0] = sc.nextInt() - 1;
		}
		for (int i = 1; i < 63; i++) {
		    for (int j = 0; j < n; j++) {
		        matrix[j][i] = matrix[matrix[j][i - 1]][i - 1];
		    }
		}
		int idx = 0;
		for (int i = 62; i >= 0; i--) {
		    if (k >= (1L << i)) {
		        idx = matrix[idx][i];
		        k -= (1L << i);
		    }
		}
		System.out.println(idx + 1);
	}
}
