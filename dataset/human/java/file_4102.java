import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		List<Integer> a = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int input = sc.nextInt();
			a.add(input);
		}
		List<Integer> b = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			int input = sc.nextInt();
			b.add(input);
		}
		List<Integer> c = new ArrayList<>();
		for (int i = 0; i < n - 1; i++) {
			int input = sc.nextInt();
			c.add(input);
		}
		int size = a.size();
		int sum = b.stream().mapToInt(Integer::valueOf).sum();
		int beforeA = -2;

		for (int i = 0; i < size; i++) {
			int tempA = a.get(i) - 1;
			if (beforeA + 1 == tempA) {
				sum += c.get(beforeA);
			}
			beforeA = tempA;
		}
		System.out.println(sum);
	}
}
