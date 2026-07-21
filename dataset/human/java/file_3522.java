import java.util.Scanner;

public class Main {

	private static final String LESS_THAN = "<";
	private static final String GREATHER_THAN = ">";
	private static final String EQUALS = "=";

	public static void main(String[] args) {

		Main myself = new Main();
		myself.execute();

	}

	/**
	 * 実処理メソッド
	 */
	public void execute() {

		Scanner sc = new Scanner(System.in);

		final String X = sc.next();
		int x = parse(X);
		final String Y = sc.next();
		int y = parse(Y);

		if (x < y) {
			System.out.println(LESS_THAN);
		} else if (x > y) {
			System.out.println(GREATHER_THAN);
		} else if (x == y) {
			System.out.println(EQUALS);
		}

	}

	private int parse(String str) {

		switch (str) {
		case "A":
			return 10;
		case "B":
			return 11;
		case "C":
			return 12;
		case "D":
			return 13;

		case "E":
			return 14;

		case "F":
			return 15;
		default:
			return -1;

		}
	}

}
