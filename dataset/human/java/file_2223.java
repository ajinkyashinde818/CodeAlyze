import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long num = sc.nextLong();
		int ans = 0;
		if (num > 1) {
			Map<Long, Long> factorMap = new HashMap<Long, Long>();
			Main main = new Main();
			main.factoring(factorMap, num);
			int con = 0;

			for (Long item : factorMap.keySet()) {
				con = 1;
				long val = factorMap.get(item);
				while (con <= val) {
					val = val - con;
					con++;
					ans++;
				}
			}
		}

		System.out.println(ans);

	}

	public void factoring(Map<Long, Long> factorMap,long num) {
		boolean isFactoringFlg = false;
		for (int i = 2; i <= Math.sqrt(num); i++) {
			if (num % i == 0 ) {
				if (factorMap.containsKey((long)i)) {
					factorMap.put((long)i, factorMap.get((long)i) + 1L);
				} else {
					factorMap.put((long)i, 1L);
				}
				num = num / i;
				isFactoringFlg = true;
				break;
			}
		}

		if (isFactoringFlg) {
			factoring(factorMap, num);
		}else {
			if (factorMap.containsKey(num)) {
				factorMap.put(num, factorMap.get(num) + 1L);
			}else {
				factorMap.put(num, 1L);
			}
		}
	}
}
