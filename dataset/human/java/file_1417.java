import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		try {
			int n = sc.nextInt();
			int m = sc.nextInt();
			sc.nextLine();

			List<String> a = new ArrayList<String>();
			for (int i = 0; i < n; i++) {
				a.add(sc.nextLine());
			}
			List<String> b = new ArrayList<String>();
			for (int i = 0; i < m; i++) {
				b.add(sc.nextLine());
			}

			for (int i = 0; i <= n - m; i++) {
				String ai = a.get(i);
				int index = ai.indexOf(b.get(0));
				if (m == 1 && index != -1) {
					System.out.println("Yes");
					return;
				}
				while (index != -1) {
					boolean match = true;
					for (int k = 1; k < m; k++) {
						if (!a.get(i + k).substring(index, index + m).equals(b.get(k))) {
							match = false;
							break;
						}
					}
					if (match) {
						System.out.println("Yes");
						return;
					}
					if (index == ai.length() - 1) {
						break;
					}
					ai = ai.substring(index + 1);
					index = ai.indexOf(b.get(0));
				}
			}

			System.out.println("No");

		} finally {
			sc.close();
		}
	}
}
