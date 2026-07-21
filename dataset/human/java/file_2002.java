import java.util.*;
import java.io.*;
import java.nio.charset.StandardCharsets;

public class Main {
	long N;
	Map<Long, Integer> origins;

	public static void main(String[] args) throws IOException {
		InputStreamReader reader = new InputStreamReader(System.in, StandardCharsets.UTF_8);
		BufferedReader in = new BufferedReader(reader);
		Main ins = new Main(in);
		ins.calc();
		ins.showResult();
	}

	Main(BufferedReader in) throws IOException {
		N = Long.parseLong(in.readLine());
		long n = N;
		this.origins = new HashMap<>();
		long divVal = 2;
		while (Math.sqrt(N) + 1 > divVal) {
			if (n % divVal == 0) {
				if (!origins.containsKey(divVal)) {
					origins.put(divVal, 1);
				} else {
					origins.put(divVal, origins.get(divVal) + 1);
				}
				n /= divVal;
			} else {
				++divVal;
			}
		}
		if (n > 1) {
			if (!origins.containsKey(n)) {
				origins.put(divVal, 1);
			} else {
				origins.put(divVal, origins.get(divVal) + 1);
			}
		}
	}

	int count(int num) {
		int result = 0;
		int base = 1;
		while (num > base * 2) {
			++result;
			num -= base;
			base++;
		}
		++result;
		return result;
	}

	void calc() {
		int result = 0;
		for (Long key : origins.keySet()) {
			int count = origins.get(key);
			int c = count(count);
			result += c;
		}
		System.out.println(result);
	}

	void showResult() {
	}
}
