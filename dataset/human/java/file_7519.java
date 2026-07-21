import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scanner = new Scanner(System.in);
		String S = scanner.next();

		S = S.replaceAll("eraser", "-");
		S = S.replaceAll("erase", "-");
		S = S.replaceAll("dreamer", "-");
		S = S.replaceAll("dream", "-");
		S = S.replaceAll("-", "");

		if (S.length() == 0)
			System.out.println("YES");
		else
			System.out.println("NO");
	}

}
