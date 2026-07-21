import java.util.Scanner;

//AtCoder Beginner Contest 160
// C - Traveling Salesman around Lake
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = Integer.parseInt(sc.next());
		int N = Integer.parseInt(sc.next());
		int[] A = new int[N];
		for (int i = 0; i < N; i++) {
			A[i] = Integer.parseInt(sc.next());
		}
		sc.close();

		int ans = Math.min(K, Math.abs((A[N - 1]) - A[0]));
		for (int i = 1; i < N; i++) {
			ans = Math.min(ans, Math.abs((K + A[i - 1]) - A[i]));
		}

		System.out.println(ans);
	};
}
