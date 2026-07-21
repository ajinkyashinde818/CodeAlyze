import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	static Main instance = new Main();

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		//入力値取得
		long N = scan.nextLong();

		//WK変数
		Map<Long, Integer> map = new HashMap<>();

		//演算
		long x = N;
		long result = 0L;

		for (long i = 2L; i * i<= x;) {
			if (x % i == 0L) {

				if (map.containsKey(i)) {
					map.put(i, map.get(i) + 1);
				} else {
					map.put(i, 1);
				}
				x /= i;
			} else {
				i++;
			}
		}

		if (x != 1) {
			if (map.containsKey(x)) {
				map.put(x, map.get(x) + 1);
			} else {
				map.put(x, 1);;
			}
		}

		for (Map.Entry<Long, Integer> entry: map.entrySet()) {

			int wk = entry.getValue();

			int i = 1;

			while (i * (i + 1) / 2 <= wk) {
				i++;
			}

			result += (i - 1);
		}


		//結果出力
		System.out.println(result);
	}
}
