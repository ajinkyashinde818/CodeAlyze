import java.util.Scanner;

// https://atcoder.jp/contests/abc049/tasks/arc065_a
public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scanner = new Scanner(System.in);
		String scanStr = scanner.nextLine();
		scanner.close();
		scanner = null;

		String[] divineArray = { "dream", "dreamer", "erase", "eraser" };

		// 入力した値を反転
		scanStr = ReverseString(scanStr);
		for (int i = 0; i < divineArray.length; i++) {
			divineArray[i] = ReverseString(divineArray[i]);
		}

		boolean flag = true;
		String str = scanStr;

		for (int i = 0; i < scanStr.length()&&flag;) {
			for (String divineStr : divineArray) {
				int length = divineStr.length();
				if(scanStr.length()-i>=length) {
					str = scanStr.substring(i, length+i);
				}

				if (str.equals(divineStr)) {
					i = i + length;
					flag = true;
					break;
				}else {
					flag = false;
				}
			}
		}

		// 結果
		returnResult(flag);
	}

	// str を反転するメソッド。
	public static String ReverseString(String str) {
		StringBuffer sb = new StringBuffer(str);
		str = sb.reverse().toString();
		sb = null;
		return str;
	}

	// 結果を返すメソッド
	public static void returnResult(boolean flag) {
		if (flag) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
	}

}
