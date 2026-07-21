import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner scanner =new Scanner(System.in);
		int N = scanner.nextInt();

		int streak = 0;
		boolean judge = false;
		for (int i = 0; i < N; i++) {
			int A = scanner.nextInt();
			int B = scanner.nextInt();
			if (A == B) {
				streak++;
			}else{
				streak = 0;
			}
			if (streak >= 3) {
				judge = true;
			}
		}

		if (judge) {
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

		scanner.close();
	}

}
