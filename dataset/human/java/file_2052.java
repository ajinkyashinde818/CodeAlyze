import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		var n = sc.nextLong();
		sc.close();

		var set = new HashSet<Long>();
		while (true) {
			var list = getDivisors(n);
			var z = 0L;
			for (var a : list) {
				if (!set.contains(a) && check(a)) {
					z = a;
					break;
				}
			}
			if (z == 0) {
				break;
			}
			set.add(z);
			n = n / z;
			//System.out.printf("%d %d %d\r\n", n, z, n / z);
		}
		System.out.println(set.size());
	}

	public static boolean check(long n) {
		var list = getDivisors(n);
		var p = list.get(0);
		while (n % p == 0) {
			n /= p;
		}
		return n == 1;
	}

	public static List<Long> getDivisors(long n) {
		var list = new ArrayList<Long>();
		for (var i = 1L; i < (long) Math.sqrt(n) + 1; i++) {
			if (n % i == 0) {
				list.add(i);
				var divisor = n / i;
				if (divisor != i) {
					list.add(divisor);
				}
			}
		}

		Collections.sort(list);
		if (list.size() > 0 && list.get(0) == 1) {
			list.remove(0);
		}
		return list;
	}
}
