import java.util.Scanner;

/**
 * Party Dress
 */
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int A, B;
		A = sc.nextInt();
		B = sc.nextInt();

		int ans = 0;

		if (A >= B) {
			ans = 1;
		} else if (B % A == 0) {
			ans = B / A;
		} else {
			ans = B / A + 1;
		}

		System.out.println(ans);
	}
}
