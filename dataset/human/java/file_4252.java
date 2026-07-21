import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int kind = sc.nextInt();
		int[] number = new int[kind + 1];
		int[] good = new int[kind + 1];
		int[] goodPlus = new int[kind];

		int mansum = 0;

		for (int i = 1; i <= kind; i++) {
			number[i] = sc.nextInt();
		}

		for (int i = 1; i <= kind; i++) {
			good[i] = sc.nextInt();
		}

		for (int i = 1; i < kind; i++) {
			goodPlus[i] = sc.nextInt();
		}

		for (int i = 1; i <= kind; i++) {
			mansum += good[i];
		}

		for (int i = 1; i < kind; i++) {
			if ((number[i] + 1) == number[i + 1]) {
				mansum += goodPlus[number[i]];
			}
		}

		System.out.println(mansum);

	}

}
