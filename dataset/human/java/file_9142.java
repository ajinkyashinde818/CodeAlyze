import java.util.Scanner;

public class Main {
	Integer steps[];
	Long results[];

	public Main(int n, Integer a[]) {
		steps = new Integer[n];
		results = new Long[n];
		for (int i = 0; i < steps.length; i++) {
			steps[i] = 1;
			results[i] = -1L;
		}
		for (int e : a) {
			steps[e] = 0;
		}

	}

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int m = s.nextInt();
		Integer a[] = new Integer[m];
		for (int i = 0; i < m; i++) {
			a[i] = s.nextInt();
		}
		System.out.println(
				new Main(n, a).calc(0));
	}

	public long calc(int prefix) {
		Long shortcut = results[prefix];
		long result;
		if (shortcut != -1L) {
			return shortcut;
		}
		if (prefix >= steps.length) {
			result = 0;
		} else if (prefix == steps.length - 1) {
			result = 1;
		} else if (prefix == steps.length - 2) {
			result = 1 + (((steps[prefix + 1] == 1) ? 1 : 0));
		} else {
			result = (((steps[prefix + 1] == 1) ? calc(prefix + 1) : 0) +
					((steps[prefix + 2] == 1) ? calc(prefix + 2)
							: 0));
			result %=  1_000_000_007L;
		}
		results[prefix] = result;
		return result;
	}
}
