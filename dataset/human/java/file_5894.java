import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc1 = new Scanner(System.in);

		String str = sc1.next();

		if (str.contains("a") && str.contains("b") && str.contains("c")) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}

		sc1.close();
	}

}
