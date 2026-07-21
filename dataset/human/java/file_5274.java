import java.util.Scanner;

public class Main {
	static Scanner scan;

	static int solve(int n) {
		int[][] memo = count(n);
		int max = 0;
		for (int w = n; w > max; w--) {
			for (int y = n - 1; y >= max - 1; y--) {
				for (int x = n - 1; x >= max - 1; x--) {
					if( x - w + 1 < 0 || y - w + 1 < 0)
						continue;
					if (isSquare(memo, x, y, w)) {
						max = (max < w)? w : max;
						break;
					}
				}
			}
		}
		return max;
	}

	static int[][] count(int n) {
		int[][] result = new int[n + 1][n + 1];
		initialize(result, 0);
		String data = null;
		int count = 0;
		for (int y = 1; y < n + 1; y++) {
			data = scan.next();
			count = 0;
			for (int x = 1; x < n + 1; x++) {
				if (data.charAt(x - 1) == '.')
					count++;
				result[y][x] = count + result[y - 1][x];
			}
		}
		return result;
	}

	static void initialize(int[][] array, int value) {
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[0].length; j++) {
				array[i][j] = value;
			}
		}
	}
	
	static boolean isSquare(int[][] memo, int x, int y, int w) {
		int s = memo[y + 1][x + 1] - memo[y + 1 - w][x + 1]	- memo[y + 1][x + 1 - w] + memo[y + 1 - w][x + 1 - w];
		return s == w * w;
	}

	public static void main(String[] args) {
		scan = new Scanner(System.in);
		int n = 0;
		while ((n = scan.nextInt()) != 0) {
			System.out.println(solve(n));
		}
		scan.close();
	}

	static void print(int[][] array){
		for (int i = 0; i < array.length; i++) {
			for (int j = 0; j < array[0].length; j++) {
				System.out.printf("%d ", array[i][j]);
			}
			System.out.println();
		}
	}
}
