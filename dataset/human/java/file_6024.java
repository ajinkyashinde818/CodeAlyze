import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
			Scanner scanner = new Scanner(System.in);
			String s = scanner.next();
			String ans = s.contains("a") && s.contains("b") && s.contains("c") ? "Yes" : "No";
			System.out.println(ans);
	}

}
