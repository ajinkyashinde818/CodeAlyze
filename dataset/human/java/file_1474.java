import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int m = sc.nextInt();
		String[] a = new String[n];

		for (int i = 0; i < n; i++) {
			a[i] = sc.next();
		}

		String[] b = new String[m];

		for (int i = 0; i < m; i++) {
			b[i] = sc.next();
		}

		for (int i = 0; i < n - m + 1; i++) {

			loop: for (int j = 0; j < n - m + 1; j++) {
				boolean flag = true;
				for (int k = 0; k < m; k++) {

					if (!(a[j + k].substring(i, i + m).equals(b[k]))) {
						flag = false;
						continue loop;
					}
				}
				if (flag == true) {
					System.out.println("Yes");
					System.exit(0);
				}

			}
		}

		System.out.println("No");
		sc.close();
	}
}
