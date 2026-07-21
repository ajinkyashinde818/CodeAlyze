import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			int n = sc.nextInt();
			int count = 0;
			int[][] ans = new int[n][n];
			for(int i = 0;i < n;i++) {
				for(int j = 0;j < 2;j++) {
					ans[i][j] = sc.nextInt();
				}
				if(ans[i][0] == ans[i][1]) {
					count++;
					if(count >= 3) {
						break;
					}
				}
				else {
					count = 0;
				}
			}
			if(count >= 3) {
				System.out.println("Yes");
			}
			else {
				System.out.println("No");
			}
		}
	}

}
