import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int a[] = new int[n];
		for (int i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		Map<Integer, Integer> bMap = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++) {
			bMap.put(i, sc.nextInt());
		}
		int c[] = new int[n - 1];
		for (int i = 0; i < n - 1; i++) {
			c[i] = sc.nextInt();
		}

		int pre = -1;
		int total = 0;
		for (int i = 0; i < n; i++) {
			total += bMap.get(a[i]-1);
			if (a[i] == pre + 1) {
				total += c[pre-1];
			}
			pre = a[i];
		}
		System.out.println(total);
		sc.close();
	}
}
