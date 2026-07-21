import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb  = new StringBuilder(sc.next());

		List<StringBuilder> wordsList = new ArrayList<StringBuilder>();
		wordsList.add(new StringBuilder("dreamer"));
		wordsList.add(new StringBuilder("dream"));
		wordsList.add(new StringBuilder("erase"));
		wordsList.add(new StringBuilder("eraser"));

		sb = sb.reverse();
		for (StringBuilder word : wordsList) {
			word = word.reverse();
		}
		while (sb.length() > 0) {
			boolean hitFlg = false;

			for (StringBuilder word : wordsList) {
				if (sb.indexOf(word.toString()) == 0) {
					sb.delete(0, word.length());
					hitFlg = true;
					break;
				}
			}
			if (!hitFlg) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}

}
