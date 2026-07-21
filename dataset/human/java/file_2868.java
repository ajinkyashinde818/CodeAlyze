import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/**
 * Flying Jenny
 */
public class Main {

	static int[] c = {4, 1, 4, 1, 2, 1, 2, 1};

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";

		while ((line = br.readLine()) != null && !line.isEmpty()) {

			StringTokenizer st = new StringTokenizer(line);

			int[] p = new int[16];
			for (int i = 0; i < 8; i++) {
				p[i] = p[i + 8] = parseInt(st.nextToken());
			}

			int min = Integer.MAX_VALUE;
			int V = Integer.MAX_VALUE;


			for (int i = 0; i < 8; i++) {
				int _min = 0;
				int _V = 0;
				for (int j = 0; j < 8; j++) {
					_min += (p[i + j] - c[j] > 0 ? p[i + j] - c[j] : 0);
					_V *= 10;
					_V += c[(8 - i + j) % 8];
				}
				if (_min < min) {
					min = _min;
					V = _V;
				} else if (_min == min) {
					if (_V < V) {
						V = _V;
					}
				}
			}

			List<String> ans = new ArrayList<>();

			for (char cc : String.valueOf(V).toCharArray()) {
				ans.add("" + cc);
			}

			System.out.println(String.join(" ", ans));
		}
	}
}
