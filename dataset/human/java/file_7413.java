import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String scStr = scanner.nextLine();
		int count = scStr.length() / 5;

		String dream = "dream";
		String dreamer = "dreamer";
		String erase = "erase";
		String eraser = "eraser";

		boolean result = false;
		boolean isEnd = false;

		for (int i = 0; i <= count; i++) {
			if (isEnd == true)
				break;
			if (scStr.endsWith(dreamer)) {
				scStr = scStr.substring(0,scStr.length()-7);
			} else if (scStr.endsWith(dream)) {
				scStr = scStr.substring(0,scStr.length()-5);
			} else if (scStr.endsWith(eraser)) {
				scStr = scStr.substring(0,scStr.length()-6);
			} else if (scStr.endsWith(erase)) {
				scStr = scStr.substring(0,scStr.length()-5);
			} else if (scStr.length() <= 7) {
				if (scStr.length() == 0) {
					result = true;
				} else if (scStr.length() == 7 && (scStr.endsWith(dreamer))) {
					result = true;
					isEnd = true;
				} else if (scStr.length() == 6 && (scStr.endsWith(eraser))) {
					result = true;
					isEnd = true;
				} else if (scStr.length() == 5 && (scStr.endsWith(dream) || scStr.endsWith(erase))) {
					result = true;
					isEnd = true;
				}else {
					isEnd = true;
				}
			}
		}
		if (result == true) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
	}

}
