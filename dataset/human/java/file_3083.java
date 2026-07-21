import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n, m, a[], b[];
		long graph[], graph2[];
		n = sc.nextInt();
		m = sc.nextInt();
		a = new int[m];
		b = new int[m];
		graph = new long[n];
		graph2 = new long[n];

		int j = 0, k = 0;

		for (int i = 0; i < m; ++i) {
			a[i] = sc.nextInt();
			b[i] = sc.nextInt();
			if (a[i] == 1 && b[i] != n)
				graph[j++] = b[i];
			if (b[i] == 1 && a[i] != n)
				graph[j++] = a[i];
			if (a[i] == n && b[i] != 1)
				graph2[k++] = b[i];
			if (b[i] == n && a[i] != 1)
				graph2[k++] = a[i];
		}
		sc.close();

		Arrays.sort(graph);
		Arrays.sort(graph2);

		boolean ans = false;

		if (j != 0) {
			for (int i = 0; i < n; ++i) {
				if (graph[i] != 0) {
					int tmp = Arrays.binarySearch(graph2, graph[i]);
					if (tmp >= 0)
						ans = true;
				}
			}
		}

		if (ans)
			System.out.println("POSSIBLE");
		else
			System.out.println("IMPOSSIBLE");
	}

}
