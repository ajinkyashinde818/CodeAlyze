import java.util.LinkedHashSet;
import java.util.Scanner;

public class Main {

	static Main instance = new Main();

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		//入力値
		int N = scan.nextInt();
		long K = scan.nextLong();

		int[] A = new int[N];

		for (int i = 0; i < N; i++) {
			A[i] = scan.nextInt();
		}

		//WK変数
		int result = 1;

		LinkedHashSet<Integer> set = new LinkedHashSet<>();
		set.add(result);

		//演算
		for (long i = 0L; i < K; i++) {
			result = A[result - 1];
			if (set.contains(result)) {
				break;
			} else {
				set.add(result);
			}
		}

		int first = 0;

		if (set.size() != K + 1) {
			int position = 1;
			for (int ele : set) {
				if (result == ele) {
					first = position;
					break;
				}
				position++;
			}
			int p = 1;
			for (int ele : set) {
				if (p == first + ((K + 1 - first) % (set.size() + 1 - first))) {
					result = ele;
					break;
				}
				p++;
			}
		}

		//結果出力
		System.out.println(result);
	}
}
