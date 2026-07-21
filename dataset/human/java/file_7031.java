import java.util.Scanner;

public class Main {

	static final boolean debugMode = false;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int k = readInt(sc);
		int n = readInt(sc);
		int[] a = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = readInt(sc);

		}

		int max = 0;
		for (int i = 0; i < n - 1; i++) {
			max = Math.max(max, a[i + 1] - a[i]);
		}

		max = Math.max(max, k - a[n - 1] + a[0]);

		System.out.println(k - max);
	}

	static int readInt(Scanner sc) {
		return Integer.parseInt(sc.next());
	}

	static void log(String s) {
		if (debugMode) {
			System.out.println(s);
		}
		return;
	}
}

class Pair {
	private int x;
	private int y;

	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public Pair() {

	}

	public Pair(int x, int y) {
		this.x = x;
		this.y = y;
	}

}
