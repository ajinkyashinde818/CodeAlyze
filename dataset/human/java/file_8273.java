import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);

		long A = sc.nextLong();
		long B = sc.nextLong();
		long ans = 0;

		int i = 1;
		while (i <= B) {
			if ((long) A * i % B == 0) {
				ans = (long) A * i;

				break;
			} else {
				i++;
			}
		}
		System.out.println(ans);
	}
}
