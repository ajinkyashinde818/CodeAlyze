import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;

/**
 * A Way to Invite Friends
 */
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		String[] words;

		int N = parseInt(br.readLine());
		int[] friends = new int[100_003];

		for (int i = 0; i < N; i++) {
			line = br.readLine();
			int a, b;
			a = parseInt(line.substring(0, line.indexOf(' ')));
			b = parseInt(line.substring(line.indexOf(' ') + 1));
			friends[a]++;
			friends[b + 1]--;
		}

		int max = 0;
		for (int i = 1; i <= N + 1; i++) {
			friends[i] += friends[i - 1];
			if (i <= friends[i] + 1 && friends[i] <= N + 1) {
				max = i;
			}
		}
		System.out.println(max - 1);
	}
}
