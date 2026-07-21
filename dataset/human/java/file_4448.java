import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		long A = sc.nextLong();
		long B = sc.nextLong();
		long C = sc.nextLong();

		long result = 0;

		if(B >= (C + 1)) {
			result = B + C;
		} else {
			result = 2 * B;

			if((C - B) >= (A + 1)) {
				result += A + 1;

			} else {
				result += (C - B);
			}
		}

		System.out.println(result);

	}

}
