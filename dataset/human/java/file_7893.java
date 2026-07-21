import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

import static java.lang.Integer.parseInt;

/**
 * Programming Contest
 */
public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		String[] words;

		int N = parseInt(br.readLine());

		int[] score = new int[102];

		StringTokenizer st = new StringTokenizer(br.readLine());

		for (int i = 0; i < N; i++) {
			score[parseInt(st.nextToken())]++;
		}

		int ans = 0;

		for (int i = 100; i >= 0; i--) {
			score[i] += score[i + 1];
			if (score[i] >= i) {
				ans = i;
				break;
			}
		}

		System.out.println(ans);
	}
}
