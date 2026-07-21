import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		new Main().run();
	}

	private void run() {
		Scanner scanner = new Scanner(System.in);
		int sum = 0;
		for (int i = 0; i < 10; i++)
			sum += scanner.nextInt();
		System.out.println(sum);
	}
}
