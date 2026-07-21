import java.util.*;

public class Main {
	
	private static String dreamer = "dreamer";
	private static String dream = "dream";
	private static String erase = "erase";
	private static String eraser = "eraser";
			
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] wordList = new String[] {
			eraser, erase, dreamer, dream
		};
		
		String input = sc.nextLine();
		for (String s: wordList) {
			input = input.replace(s, ".");
		}
		
		for (int i = 0; i < input.length(); i++) {
			if (input.charAt(i) != '.') {
				System.out.println("NO");
				return;
			}
		}
		
		System.out.println("YES");
		
	}
	
}
