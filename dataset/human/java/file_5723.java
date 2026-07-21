import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		if (isAbc(s)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}

	public static boolean isAbc(String s) {
		if (s.equals("abc")) {
			return true;
		} else if (s.equals("acb")) {
			return true;
		} else if (s.equals("bac")) {
			return true;
		} else if (s.equals("bca")) {
			return true;
		} else if (s.equals("cab")) {
			return true;
		} else if (s.equals("cba")) {
			return true;
		}

		return false;

	}

}
