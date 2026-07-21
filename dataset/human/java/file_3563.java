import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String[] a = new String[2];
		int[] b = new int[2];

		for (int i = 0; i < 2; i++) {
			a[i] = sc.next();

			if (a[i].equals("A")) {
				b[i] = 10;
			} else if (a[i].equals("B")) {
				b[i] = 11;
			} else if (a[i].equals("C")) {
				b[i] = 12;
			} else if (a[i].equals("D")) {
				b[i] = 13;
			} else if (a[i].equals("E")) {
				b[i] = 14;
			} else if (a[i].equals("F")) {
				b[i] = 15;
			}
		}

		if (b[0] < b[1]) {
			System.out.println("<");
		} else if (b[0] > b[1]) {
			System.out.println(">");
		} else {
			System.out.println("=");
		}

	}
}
