import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		sc.close();

		int cnt = 0;
		for (int i = Math.max(a, b); ; i--) {
			if (a % i == 0 && b % i == 0) {
				cnt++;
				if (cnt == k) {
					System.out.println(i);
					return;
				}
			}
		}
	}
}
