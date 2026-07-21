import java.util.*;

public class Main {
	int N;
	String S;
	List<Set<Character>> groups;
	Map<Character, Integer> map;
	long[] results = null;
	long result = 0;

	Main() {
		Scanner in = new Scanner(System.in);
		N = Integer.parseInt(in.nextLine());
		S = in.nextLine();
		in.close();

		this.map = new HashMap<>();
		this.results = new long[N];
		this.results[0] = 1;
		this.map.put(S.charAt(0), 1);
		for (int i = 1; i < S.length(); ++i) {
			Character c = S.charAt(i);
			long addVal = getAddVal(map, c);
			results[i] = (results[i - 1] + addVal) % 1000000007L;
			// System.out.println(results[i] + ", " + addVal);
			if (map.containsKey(c)) {
				map.put(c, map.get(c) + 1);
			} else {
				map.put(c, 1);
			}
		}
	}

	long getKaijo(int val) {
		long result = (long) Math.pow(2.0, (double) val);
		return result;
	}

	long getKaijo(Map<Character, Integer> map, Character c) {
		long result = 1;
		for (Character key : map.keySet()) {
			if (key.equals(c)) {
				continue;
			}
			result *= map.get(key) + 1;
			result %= 1000000007L;
		}
		return result;
	}

	long getAddVal(Map<Character, Integer> map, Character c) {
		long result = getKaijo(map, c);
		/*
		for (Character key : map.keySet()) {
			if (key.equals(c)) {
				continue;
			}
			if (map.get(key) >= 2) {
				result += map.get(key);
			}
		}*/
		return result;
	}

	void show() {
		System.out.println(results[results.length - 1]);
	}

	void calc() {

		result = calcCombi(map.size());
		System.out.println(result);
		for (Character c : map.keySet()) {
			if (map.get(c) > 1) {
				result += map.get(c);
			}
		}
	}

	long calcCombi(int val) {
		long result = 0;
		for (int i = 1; i <= val; ++i) {
			result += calcCombi(val, i);
		}
		return result;
	}

	long calcCombi(int val, int c) {
		if (c > Math.floorDiv(val, 2)) {
			return calcCombi(val, val - c);
		}
		long result = 1;
		for (int i = 1; i <= c; ++i) {
			result *= val - i + 1;
		}
		for (int i = 1; i <= c; ++i) {
			result /= i;
		}
		return result;
	}

	public static void main(String[] args) {
		Main ins = new Main();
		// ins.calc();
		ins.show();
	}

}
