import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

import static java.lang.Integer.parseInt;

/**
 * Rearranging a Sequence
 */
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		String[] words;

		line = br.readLine();

		int n, m;
		n = parseInt(line.substring(0, line.indexOf(' ')));
		m = parseInt(line.substring(line.indexOf(' ') + 1));

		List<Integer> list = new ArrayList<>(n + m);
		boolean[] dup = new boolean[n + 1];

		for (int i = n; i >= 1; i--) list.add(i);

		for (int i = 0; i < m; i++) list.add(parseInt(br.readLine()));

		StringBuilder sb = new StringBuilder();

		for (int i = list.size() - 1; i >= 0; i--) {
			int e = list.get(i);
			if (!dup[e]) {
				sb.append(e).append('\n');
				dup[e] = true;
			}
		}

		System.out.print(sb.toString());

	}
}
