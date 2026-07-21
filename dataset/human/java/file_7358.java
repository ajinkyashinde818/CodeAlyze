import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashMap;

public final class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String in = br.readLine();
		System.out.println(new Solver().solve(in));
	}
}

class Solver {

	String solve(String in) {
		HashMap<String, Boolean> m = new HashMap<String, Boolean>();
		m.put("dream", true);
		m.put("dreamer", true);
		m.put("erase", true);
		m.put("eraser", true);
		int i;
		for (i = 0; i < in.length() - 4;) {
			if (i + 4 < in.length() && m.containsKey(in.substring(i, i + 5))) {
				if (i + 6 < in.length() && m.containsKey(in.substring(i, i + 7))) {
					if (i + 9 < in.length() && m.containsKey(in.substring(i + 5, i + 10))) {
						i += 5;
					} else {
						i += 7;
					}
				} else if (i + 5 < in.length() && m.containsKey(in.substring(i, i + 6))) {
					i += 6;
				} else {
					i += 5;
				}
			} else {
				return "NO";
			}

		}
		return i >= in.length() ? "YES" : "NO";

	}
}
