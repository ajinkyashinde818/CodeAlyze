import java.util.*;
import java.lang.*;
import java.math.*;

public class Main {
	Scanner sc = new Scanner(System.in);

	void run() {
		for (;;) {
			String buffer = sc.nextLine();
			int size = Integer.valueOf(buffer);
			if (size == 0)
				break;
			boolean[][] map = new boolean[size + 1][size + 1];
			for (int i = 0; i < size; i++) {
				buffer = sc.nextLine();
				for (int j = 0; j < size; j++) {
					map[i + 1][j + 1] = buffer.charAt(j) == '.';
				}
			}
			int[][] sq = new int[size+1][size+1];
			int max = 0;
			for (int i = 1; i < size + 1; i++) {
				for (int j = 1; j < size + 1; j++) {
					if (map[i][j]) {
						if (map[i - 1][j] && map[i - 1][j - 1] && map[i][j - 1]) {
							sq[i][j] = Math.min(Math.min(sq[i - 1][j],sq[i - 1][j - 1] ), sq[i][j - 1])+1;
						} else {
							sq[i][j] = 1;
						}
					}
					if(max < sq[i][j]) max = sq[i][j];
				}
			}
			System.out.println(max);
		}

	}

	public static void main(String[] args) {
		Main m = new Main();
		m.run();
	}
}
