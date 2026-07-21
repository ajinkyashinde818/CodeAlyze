import java.util.Scanner;
import javax.swing.tree.TreeNode;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.Vector;
import static java.lang.System.*;


public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
	
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		int ans = Integer.MAX_VALUE;
		
		
		
		
		int[] sum = new int[m];
		for(int i = 1; i < (1<<n); ++i) {
			Arrays.fill(sum, 0);
			int cost = 0;
			for(int j = 0; j < n; j++) {
				if((1&(i>>j)) == 1) {
					for(int k = 0; k < m; k++) {
						sum[k] += a[j][k];
					}
					cost += c[j];
				}
			}
			boolean judge = true;
			for(int j = 0; j < m; j++) {
				if(sum[j] < x) {
					judge = false;
					break;
				}
			}
			if(judge) {
				ans = Math.min(ans, cost);
			}
		}
		System.out.println(ans<Integer.MAX_VALUE? ans : -1);
	}
	
}
