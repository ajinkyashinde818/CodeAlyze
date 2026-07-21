import java.util.Scanner;

public class Main {

	/**
	 * @param args
	 */
	Scanner sc = new Scanner(System.in);

	void run() {
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			sum += sc.nextInt();
		}
		System.out.println(sum);

	}

	public static void main(String[] args) {

		new Main().run();
	}

}
