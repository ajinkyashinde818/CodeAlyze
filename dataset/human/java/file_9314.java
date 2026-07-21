import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int count = 0;
		boolean judge = false;
		for (int i = 0; i < n; i++) {
			int d1 = sc.nextInt();
			int d2 = sc.nextInt();
			if (d1 == d2) {
				count = count + 1;
			} else {
				count = 0;
			}
			if (count == 3) {
				judge = true;
			}
		}
		if (judge) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

}
