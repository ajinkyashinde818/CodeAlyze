import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner sc = new Scanner(System.in)) {
			int N = sc.nextInt();
			PriorityQueue<Integer> q = new PriorityQueue<>();
			int minus_cnt = 0;
			for (int i = 0; i < N; i++) {
				int a = sc.nextInt();
				if (a < 0) {
					minus_cnt++;
					a = (-1) * a;
				}
				q.add(a);
			}
			long sum = 0;
			if (minus_cnt % 2 != 0) {
				sum -= q.poll();
			}
			while (!q.isEmpty()) {
				sum += q.poll();
			}
			System.out.println(sum);
		}
	}
}
