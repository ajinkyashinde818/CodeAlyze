import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		Map<Long, Long> divNum = new HashMap<>();
		long tmpN = N;
		if (N == 1) {
			System.out.println(0);
			System.exit(0);
		}
		for (long i = 2; Math.pow(i, 2) <= tmpN; i++) {
			if (N % i == 0) {
				N = N / i;
				if (divNum.get(i) == null) {
					divNum.put(i, (long) 1);
				} else {
					divNum.put(i, divNum.get(i) + 1);
				}
				if (N == 1) {
					break;
				}
				i--;
			}
		}
		// 1以外だったら残ったNも約数
		if (N != 1) {
			if (divNum.get(N) == null) {
				divNum.put(N, (long) 1);
			} else {
				divNum.put(N, divNum.get(N) + 1);
			}
		}
		long res = 0;
		loop: for (Entry<Long, Long> entry : divNum.entrySet()) {
			for (int i = 1; i < 48; i++) {
				long num = (i + 1) * (i + 2) / 2;
				if (entry.getValue() < num) {
					res += i;
					continue loop;
				}
			}
		}
		System.out.println(res);
	}
}
