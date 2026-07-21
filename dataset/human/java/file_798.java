import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		int R = scanner.nextInt();

		// R = X - 100(10-N)
		// X = R + (100(10-N))
		int result = N<10 ? R + 100*(10-N) : R;
		System.out.println(result);


	}

}
