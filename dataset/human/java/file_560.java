import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		int ans = 0;
		if(n < 10) {
			ans = 100 * (10 - n) + r;
		}else {
			ans = r;
		}
		System.out.println(ans);

		sc.close();
	}
}
