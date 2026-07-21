import java.util.Scanner;

public class Main {

	public static String dream = "dream";
	public static String dreamer = "dreamer";
	public static String erase = "erase";
	public static String eraser = "eraser";

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();

		int pointer = s.length();
		while(true) {
			if (isMatchedString(pointer, s, dream)) {
				pointer -= dream.length();
			} else if (isMatchedString(pointer, s, dreamer)) {
				pointer -= dreamer.length();
			} else if (isMatchedString(pointer, s, erase)) {
				pointer -= erase.length();
			} else if (isMatchedString(pointer, s, eraser)) {
				pointer -= eraser.length();
			} else {
				System.out.println("NO");
				break;
			}
			if (isFinished(pointer, s)) {
				System.out.println("YES");
				break;
			}
		}
	}


	public static boolean isMatchedString(int endIndex, String s, String d) {
		return 0 <= endIndex - d.length() && s.substring(endIndex - d.length(), endIndex).equals(d);
	}

	public static boolean isFinished(int index, String s) {
		return index == 0;
	}

}
