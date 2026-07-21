import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long K = sc.nextLong();

		int[] dir = new int[N];
		for (int i = 0; i < N; i++) {
			dir[i] = sc.nextInt();
		}

		int[] flgs = new int[N];
		Arrays.fill(flgs, -1);
		int steps = 0;
		int now = 1;
		int target = dir[now - 1];
		flgs[now - 1] = steps;
		steps++;
		while (true) {
			now = target;
			target = dir[now - 1];
			if (flgs[now - 1] == -1) {
				flgs[now - 1] = steps;
			}else {
				K =(K - steps)%(steps-flgs[now - 1]);
				break;
			}
			if (K - steps == 0) {
				K = K - steps;
				break;
			}
			steps++;
		}
		for (int i = 0; i < K; i++) {
			now = target;
			target = dir[now - 1];
		}
		System.out.println(now);
	}
}
