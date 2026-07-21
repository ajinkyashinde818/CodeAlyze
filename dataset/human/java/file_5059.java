import java.util.*;

// TLEになったので文字列結合はStringBuilderで
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String first = sc.next();
		int n = Integer.parseInt(sc.next());

		// 入力しながらクエリにこたえていこう
		StringBuilder result = new StringBuilder();
		result.append(first);
		int reverse = 1;
		for (int i = 0; i < n; i++) {

			if (Integer.parseInt(sc.next()) == 1) {
				reverse *= -1;
			} else {
				int kind = Integer.parseInt(sc.next());
				if ((kind == 1 && reverse == 1) || (kind == 2 && reverse == -1)) {
					result.insert(0, sc.next());
					// result = sc.next() + result;
				} else {
					result.append(sc.next());
					// result = result + sc.next();
				}
			}
		}

		// 最後に今が逆行状態なら結果反転
		if (reverse == -1) {
			result.reverse();
		}

		System.out.println(result);

	}

}
