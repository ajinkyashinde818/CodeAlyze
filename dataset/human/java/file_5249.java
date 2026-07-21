import static java.lang.Math.min;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = "";

		while (!(line = br.readLine()).equals("0")) {

			//
			int n = Integer.parseInt(line);
			int[][] grid = new int[n + 2][n + 2];

			for (int i = 0; i < n; i++) {
				line = br.readLine();
				for (int j = 0; j < n; j++) {
					grid[i + 1][j + 1] = line.charAt(j) == '.' ? 1 : 0;
				}
			}

			//
			int max = 0;
			for (int i = 1; i < n + 1; i++) {
				for (int j = 1; j < n + 1; j++) {
					if (grid[i][j] != 0) {
						int min;
						min = (int) min(grid[i - 1][j - 1], grid[i - 1][j]);
						min = (int) min(min, grid[i][j - 1]);
						grid[i][j] = min + 1;
						if (grid[i][j] > max) {
							max = grid[i][j];
						}
					}
				}
			}
			System.out.println(max);

		}

	}

}
