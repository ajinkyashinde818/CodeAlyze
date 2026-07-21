import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String s = (new Main()).run();
		System.out.println(s);
	}

	public String run() {

		Entity e = input();
		int a = e.getA();
		int b = e.getB();
		int c = e.getC();

		int eaten = 0;
		while (true) {

			// eatc
			if (c > 0) {
				c--;
				eaten++;
			} else {
				break;
			}

			if (b > 0) {
				b--;
				eaten++;

				continue;
			}

			if (a > 0) {
				a--;
				continue;
			}

			if (a == 0 && b == 0) {
				break;
			}

		}

		// eaten += c;
		eaten += b;

		return "" + eaten;

	}

	private Entity input() {

		Scanner scan = new Scanner(System.in);
		String tmp = scan.nextLine();

		scan.close();

		String[] tmps = tmp.split("\\s");
		int[] a = new int[tmps.length];

		for (int i = 0; i < tmps.length; i++) {
			a[i] = Integer.parseInt(tmps[i]);
		}

		Entity e = new Entity();
		e.setA(a[0]);
		e.setB(a[1]);
		e.setC(a[2]);

		return e;

	}

	private class Entity {

		int a = -1;
		int b = -1;
		int c = -1;

		public int getA() {
			return a;
		}

		public void setA(int a) {
			this.a = a;
		}

		public int getB() {
			return b;
		}

		public void setB(int b) {
			this.b = b;
		}

		public int getC() {
			return c;
		}

		public void setC(int c) {
			this.c = c;
		}

	}

}
