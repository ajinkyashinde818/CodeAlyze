import java.util.Iterator;
import java.util.Scanner;
import java.util.TreeSet;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int a = sc.nextInt();
		int b = sc.nextInt();
		int k = sc.nextInt();
		int ans = 0;
		TreeSet<Integer> ts = new TreeSet<>();
		while (ans <= Math.min(a, b)) {
			ans++;
			if (a % ans == 0 && b % ans == 0) {
				ts.add(ans);
			}
		}
		Iterator<Integer> ite = ts.iterator();
		for (int i = 0; i < ts.size() - k; i++) {
			ite.next();
		}
		System.out.println(ite.next());
	}
}
