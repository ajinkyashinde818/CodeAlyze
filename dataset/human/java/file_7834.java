import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String str[] = br.readLine().split(" ");

		int n = Integer.parseInt(str[0]);
		long k = Long.parseLong(str[1]);

		int a[] = new int[n];

		str = br.readLine().split(" ");
		for (int i = 0; i < n; i++) {
			a[i] = Integer.parseInt(str[i]) - 1;
		}

		List<Integer> path = new ArrayList<>();

		Set<Integer> set = new HashSet<>();
		int next = 0;

		while (!set.contains(next)) {
			path.add(next);
			set.add(next);
			next = a[next];
		}

		int size = path.size();
		int pred = path.indexOf(next);
		int hsize = size - pred;

		if (k <= pred) {
			System.out.println(path.get((int) k) + 1);
		} else {
			System.out.println(path.get((int) ((k - pred) % hsize) + pred) + 1);
		}
	}
}
