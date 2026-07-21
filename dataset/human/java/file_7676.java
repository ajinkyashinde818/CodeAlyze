import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		long k = sc.nextLong();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt() - 1;
		}
		int dist[] = new int[n];
		boolean visited[] = new boolean[n];
		int i = 0, count = 0;
		int loop = -1, loopL = 0, distFromZ = 0;
		while (true) {
			if (!visited[i]) {
				visited[i] = true;
				dist[i] = count++;
				i = a[i];
			} else {
				distFromZ = dist[i];
				loopL = count - dist[i];
				dist[i] = count - dist[i];
				loop = i;
				break;
			}
		}
		if (k >= distFromZ) {
			k -= distFromZ;
			k = k % loopL;
			i = loop;
			while (k != 0) {
				i = a[i];
				k--;
			}
			System.out.println(i + 1);
		} else {
			i = 0;
			while (k != 0) {
				i = a[i];
				--k;
			}
			System.out.println(i + 1);
		}
	}
}
