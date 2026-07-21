import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		// 文字列の入力
		String s = sc.next();
		String t = sc.next();

		List<String> sArray = new ArrayList<String>();
		for (int i = 0; i < s.length(); i++) {
			sArray.add(s.substring(i, i + 1));
		}
		Collections.sort(sArray);
		String cs = "";
		for (String string : sArray) {
			cs = cs + string;
		}
		List<String> tArray = new ArrayList<String>();
		for (int i = 0; i < t.length(); i++) {
			tArray.add(t.substring(i, i + 1));
		}
		Collections.sort(tArray);
		String ct = "";
		for (String string : tArray) {
			ct = string + ct;
		}

		if (cs.compareTo(ct) < 0) {
			System.out.println("Yes");

		} else {
			System.out.println("No");

		}

	}
}
