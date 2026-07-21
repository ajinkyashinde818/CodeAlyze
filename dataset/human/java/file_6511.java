import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int s = sc.nextInt();
		int cnt = 0;
		for (int i = 0; i <= k; i++) {
			for (int j = 0; j <= k; j++) {
				if (s - i - j < 0 || s - i - j > k) {
					continue;
				}
				cnt++;
			}
			
		}
		System.out.println(cnt);
	}
}
