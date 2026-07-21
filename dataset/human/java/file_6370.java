import java.util.Scanner;
import java.util.Stack;

public class Main {

	final int[][] dir = { { -1, -1 }, { -1, 1 }, { 1, -1 }, { 1, 1 } };

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int k = readInt(sc);
		int s = readInt(sc);

		int cnt = 0;

		for (int a = 0; a <= k; a++) {
			for (int b = 0; b <= k; b++) {
				int c = s - a - b;
				if (c >= 0 && c <= k) {
					cnt++;
				}
			}
		}
		System.out.println(cnt);
	}

	static int readInt(Scanner sc) {
		return Integer.parseInt(sc.next());
	}

	static double calcDistance(Pair p1, Pair p2) {
		return Math.pow(Math.pow(p1.getX() - p2.getX(), 2) + Math.pow(p1.getY() - p2.getY(), 2), 0.5);
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
