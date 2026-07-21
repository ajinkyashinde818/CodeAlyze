import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		if (N % 10 == 9 || N / 10 == 9)
			System.out.println("Yes");
		else
			System.out.println("No");
		scanner.close();
	}
}
