import java.util.Scanner;
import java.util.Queue;
import java.util.ArrayDeque;
import java.util.Arrays;
 
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int[][] d = new int[2][n];
		for(int i = 0; i < n; i++) {
			d[0][i] = sc.nextInt();
			d[1][i] = sc.nextInt();
		}
		String ans = "No";
		for(int i = 0; i < n - 2; i++) {
			if(d[0][i]==d[1][i] && d[0][i+1]==d[1][i+1] && d[0][i+2]==d[1][i+2] ) {
				ans = "Yes";
			}
		}
		System.out.println(ans);
	}

}
