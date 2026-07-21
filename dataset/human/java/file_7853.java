import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		var sc = new Scanner(System.in);
		var n = sc.nextInt();
		var k = sc.nextLong();
		var a = new int[n];
		for (var i = 0; i < n; i++) {
			a[i] = sc.nextInt();
		}
		sc.close();

		var set = new HashSet<Integer>();
		var list = new ArrayList<Integer>();
		var tn = 1;
		var count = 0;
		for (var i = 0; i < n; i++) {
			count++;
			tn = a[tn - 1];
			if (count == k) {
				break;
			}
			if (set.contains(tn)) {
				var i2 = list.indexOf(tn);
				var index2 = (int)(i2 + (k - count) % (list.size() - i2));
				tn = list.get(index2);
				break;
			}
			set.add(tn);
			list.add(tn);
		}

		System.out.println(tn);
	}
}
