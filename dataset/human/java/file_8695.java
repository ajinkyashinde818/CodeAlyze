import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		int a = scn.nextInt();
		int b = scn.nextInt();
		int k = scn.nextInt();
		int n;
		if (a - b > 0) {
			n = b;
		} else {
			n = a;
		}
		for (int i = n; 0 < i; i--) {
			if (a % i == 0 && b % i == 0) {
				k--;
				if (k == 0) {
					System.out.println(i);
					break;
				}
			}
		}
		scn.close();
	}
}
