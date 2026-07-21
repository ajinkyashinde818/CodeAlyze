import java.util.LinkedHashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);


		Map<Long,Integer> factMap = factorization(stdIn.nextLong());
		stdIn.close();

		if(factMap.isEmpty()) { //1のとき
			System.out.println(0);
			return;
		}

		int cnt = 0;
		for (Entry<Long, Integer> e : factMap.entrySet()) {
			cnt += countMin(e.getValue());
		}

		System.out.println(cnt);

	}

	private static Map<Long, Integer> factorization(long n) {
		Map<Long, Integer> factMap = new LinkedHashMap<Long, Integer>();

		while (n != 1) {
			if (n % 2 == 0) {
				factMap.putIfAbsent(2L, 0);
				factMap.replace(2L, factMap.get(2L) + 1);
				n /= 2;
				continue;
			}

			long d = 3;
			while (true) {

				if(d * d == n) {
					factMap.putIfAbsent(d, 0);
					factMap.replace(d, factMap.get(d) + 2);
					n = 1;
					break;
				}

				if (d * d >= n) {
					factMap.put(n, 1);
					n = 1;
					break;
				}

				if(n % d == 0) {
					factMap.putIfAbsent(d, 0);
					factMap.replace(d, factMap.get(d) + 1);
					n /= d;
					continue;
				}

				d += 2;
			}

		}

		return factMap;
	}

	private static int countMin(int pow) {
		return (int) Math.floor((Math.sqrt(2*pow + 0.25) - 0.5));

	}
}
