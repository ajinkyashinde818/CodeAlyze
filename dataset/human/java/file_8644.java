import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int A = scan.nextInt();
		int B = scan.nextInt();
		int K = scan.nextInt();

		List<Integer> list = new ArrayList<>();
		int min = Math.min(A, B);
		for (int i = 1; i <= min; i++) {
			if (A % i == 0 && B % i == 0) {
				list.add(i);
			}
		}
		Collections.sort(list);
		System.out.println(list.get(list.size() - K));

	}
}
