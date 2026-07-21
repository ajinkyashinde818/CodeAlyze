import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import static java.lang.Integer.parseInt;

public class Main {

	static int MAX = 999 + 51;
	static char TERM = 'Z';

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;

		while ((line = br.readLine()) != null && !line.isEmpty()) {

			int n = parseInt(line);
			if (n == 0) break;

			//load and pre proc.
			char[][] board = new char[n][MAX];
			int check = 0;
			for (int i = 0; i < n; i++) {
				line = br.readLine();
				for (int j = 0; j < line.length(); j++) {
					char c = line.charAt(j);
					board[i][j] = c;
					if (c == '.') {
						check++;
						if (line.charAt(j + 1) >= 'a') {
							board[i][j] = '+';
							check--;
						}
					}
				}
				board[i][line.length()] = TERM;
			}

			//write off
			//vertical bar.
			for (int j = 0; j < MAX; j++) {
				for (int i = n - 1; i > 0; i--) {
					char c = board[i][j];
					if (c == '+') {
						for (int k = i - 1; k > 0; k--) {
							if (board[k][j] == '.') {
								board[k][j] = '|';
								check--;
							} else break;
						}
					} else if (c == '.') {
						board[i][j] = ' ';
						check--;
					}
				}
				if (check == 0) break;
			}

			//ans.
			StringBuilder sb = new StringBuilder();
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < MAX; j++) {
					char c = board[i][j];
					if (c == TERM) break;
					sb.append(board[i][j]);
				}
				sb.append('\n');
			}
			System.out.print(sb.toString());
			
		} //end while
	} //end main
}
