import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int x = 0;

		// 整数の入力
		String val = sc.next();

		val = val.substring(0, val.length()-8);
		System.out.println(val);

		sc.close();
	}

}
