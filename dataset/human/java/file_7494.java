import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String S = sc.next();

		S = S.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", "");

		println(S.equals("") ? "YES" : "NO");
	}

	public static String remove(String str, String str2) {
		int index = str.indexOf(str2);
		str.substring(0, index);
		str = new String(str.substring(0, index) + str.substring(index+str2.length()));
		return str;
	}
	public static void print(Object o) {
		System.out.print(o);
	}

	public static void println(Object o) {
		System.out.println(o);
	}
}
