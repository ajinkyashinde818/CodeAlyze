import java.util.Scanner;

//AtCoder Beginner Contest 140
//B	Buffet
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		int[] aList = new int[N];
		int[] bList = new int[N];
		int[] cList = new int[N - 1];
		for (int i = 0; i < N; i++) {
			aList[i] = Integer.parseInt(sc.next());
		}
		for (int i = 0; i < N; i++) {
			bList[i] = Integer.parseInt(sc.next());
		}
		for (int i = 0; i < N - 1; i++) {
			cList[i] = Integer.parseInt(sc.next());
		}
		sc.close();

		int ans = 0;
		for (int i = 0; i < N; i++) {
			ans += bList[aList[i] - 1];
			if (i > 0) {
				if (aList[i] == aList[i - 1] + 1) {
					ans += cList[aList[i] - 1 - 1];
				}
			}
		}

		System.out.println(ans);
	}
}
