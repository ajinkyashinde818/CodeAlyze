import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		String[] a = new String[n];
		String[] b = new String[m];

		for (int i = 0; i < n; i++) {
			a[i] = scanner.next();
		}
		for (int i = 0; i < m; i++) {
			b[i] = scanner.next();
		}

		int count = 0;
		for (int i = 0; i < n - m+1; i++) {
			for (int j = 0; j < n - m+1; j++) {
				for (int k = 0; k < m; k++) {
					String str = a[i + k].substring(j, j + m);
					//System.out.println(str + ":" + b[k]);
					if (str.equals(b[k])) {
						count++;
					}
				}
				if (count == m) {
					System.out.println("Yes");
					return;
				}
				count = 0;
			}
		}
		System.out.println("No");
	}
}
