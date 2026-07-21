import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int A = scan.nextInt();
		int B = scan.nextInt();
		int K = scan.nextInt();

		int cnt = 0;
		for (int i = 1; i <= 100; i++) {
			if (A % (101-i) == 0 && B % (101-i) == 0) {
				cnt++;
				if (cnt == K) {
					System.out.println(101-i);
					return;
				}
			}
		}

	}
}
