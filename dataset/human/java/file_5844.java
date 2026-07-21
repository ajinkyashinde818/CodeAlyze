import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		int acnt = 0;
		int bcnt = 0;
		int ccnt = 0;

		for (int i = 0; i < 3; i++) {
			if (str.substring(i, i + 1).equals("a")) {
				acnt++;
			}
			if (str.substring(i, i + 1).equals("b")) {
				bcnt++;
			}
			if (str.substring(i, i + 1).equals("c")) {
				ccnt++;
			}
		}
		if (acnt == 1 && bcnt == 1 && ccnt == 1) {
			System.out.println("Yes");

		} else {
			System.out.println("No");
		}
	}

}
