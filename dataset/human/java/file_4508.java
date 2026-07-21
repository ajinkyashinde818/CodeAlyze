import java.util.Scanner;

public class Main {

	public static void main(String... args) {

		Scanner sc = new Scanner(System.in);

		// まずい解毒剤クッキー数
		int badMedichineCount = Integer.parseInt(sc.next());

		// おいしい解毒剤クッキー数
		int goodMedichineCount = Integer.parseInt(sc.next());

		// おいしい毒入りクッキー数
		int poisonCount = Integer.parseInt(sc.next());

		if (poisonCount <= (goodMedichineCount + badMedichineCount)) {
			System.out.println(poisonCount + goodMedichineCount);
		} else {
			System.out.println((goodMedichineCount * 2) + badMedichineCount + 1);
		}

	}

}
