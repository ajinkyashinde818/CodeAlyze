import java.util.ArrayList;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		try {
			Scanner scanner = new Scanner(System.in);

			int A = scanner.nextInt();
			int B = scanner.nextInt();
			int K = scanner.nextInt();

			List<Integer> answerList = new ArrayList<>();

			int loopCountMax = A > B ? B : A;

			for (int i = 1; i <= loopCountMax; i++) {
				if (A % i == 0 && B % i == 0) answerList.add(i);
			}

			System.out.println(answerList.get(answerList.size() - K));
			scanner.close();
		} catch (InputMismatchException e) {
			System.out.println("整数を入力してください。");
		}
	}
}
