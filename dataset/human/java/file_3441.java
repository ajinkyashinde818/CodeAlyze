import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String string = scanner.nextLine();
		char[] letters = string.toCharArray();
		
		String ans = "No";
		for (int i = 0; i < letters.length; i++) {
			if (letters[i]=='9') {
				ans="Yes";
			}
		}

		System.out.println(ans);
		scanner.close();
	}

}
