import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[][] d = new int[n][2];
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < 2; j++) {
				d[i][j] = sc.nextInt();
			}
		}
		int count = 0;
		String s = "No";
		for(int i = 0; i < n; i++) {
			if(d[i][0]==d[i][1]) {
				count++;
			}
			else {
				count = 0;
			}
			if(count>=3) {
				s = "Yes";
			}
		}
		System.out.println(s);
	}
}
