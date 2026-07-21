import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		boolean flg = false;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			sc.nextLine();
			int a = sc.nextInt();
			int b = sc.nextInt();
			if (a == b) {
				cnt++;
				if (cnt == 3) {
					flg = true;
				}
			} else {
				cnt = 0;
			}
		}
		String ans = flg ? "Yes" : "No";
		System.out.println(ans);
	}
}
