import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int N = scanner.nextInt();
		List<Integer> A = new ArrayList<>();
		List<Integer> B = new ArrayList<>();
		List<Integer> C = new ArrayList<>();
		for (int i = 0; i < N; i++) {
			A.add(scanner.nextInt());
		}
		for (int i = 0; i < N; i++) {
			B.add(scanner.nextInt());
		}
		for (int i = 0; i < N - 1; i++) {
			C.add(scanner.nextInt());
		}
		scanner.close();
		int score = 0;
		int tmp = 0;
		for (int i = 0; i < N; i++) {
			int num = A.get(i);
			int current_score = B.get(num - 1);
			score += current_score;
			if (i != 0 && tmp + 1 == num) {
				score += C.get(tmp - 1);
			}
			tmp = num;
		}
		System.out.println(score);
	}
}
