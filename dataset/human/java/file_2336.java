/**
 * King's Inspection
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";

		char[] stations = new char[52];
		for (int i = 0; i < 26; i++) {
			stations[i] = (char) ('a' + i);
		}
		for (int i = 0; i < 26; i++) {
			stations[i + 26] = (char) ('A' + i);
		}

		while ((line = br.readLine()) != null && !line.isEmpty()) {
			int n = parseInt(line);
			if (n == 0) break;

			int[] keys = new int[n];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int i = 0; i < n; i++) {
				keys[i] = parseInt(st.nextToken());
			}

			line = br.readLine();
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < line.length(); i++) {
				char c = line.charAt(i);
				int j;
				if ('a' <= c && c <= 'z') {
					j = c - 'a';
				} else {
					j = c - 'A' + 26;
				}
				j -= keys[i % n];
				if (j < 0) {
					j += 52;
				}
				sb.append(stations[j]);
			}
			System.out.println(sb.toString());
		} //end while
	} //end main
}
