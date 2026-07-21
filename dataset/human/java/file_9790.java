import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] costs = new int[n];
		int[][] degrees = new int[n][m];
		for (int i = 0; i < n; i++) {
		    costs[i] = sc.nextInt();
		    for (int j = 0; j < m; j++) {
		        degrees[i][j] = sc.nextInt();
		    }
		}
		int min = Integer.MAX_VALUE;
		for (int i = 1; i < (1 << n); i++) {
		    int[] current = new int[m];
		    int sum = 0;
		    for (int j = 0; j < n; j++) {
		        if ((i & (1 << j)) == 0) {
		            continue;
		        }
		        sum += costs[j];
		        for (int k = 0; k < m; k++) {
		            current[k] += degrees[j][k];
		        }
		    }
		    boolean flag = true;
		    for (int j = 0; j < m; j++) {
		        if (current[j] < x) {
		            flag = false;
		            break;
		        }
		    }
		    if (flag) {
		        min = Math.min(min, sum);
		    }
		}
		if (min == Integer.MAX_VALUE) {
		    System.out.println(-1);
		} else {
		    System.out.println(min);
		}
	}
}
