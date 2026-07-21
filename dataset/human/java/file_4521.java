import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();
		sc.close();

		int ans = 0;
		if(A + B >= C) {
			ans = B + C;
		}else {
			ans  = 2 * B + A + 1;
		}
		System.out.println(ans);
	}
}
