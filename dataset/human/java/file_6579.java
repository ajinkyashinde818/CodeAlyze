import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		 
		//ある値の最大値
		int k = scanner.nextInt();
		// 合計値
		int s = scanner.nextInt();
		int count = 0;
		
		for (int i = 0; i <=k; i++) {
			for (int j = 0; j <= k; j++) {
				int t = s - i - j;
				if (t >= 0 && t <= k) {
					count ++;
				}
			}
		}
		System.out.println(count);
	}
}
