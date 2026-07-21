import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		int k = scan.nextInt();
		int n = scan.nextInt();

		List<Integer> a = new ArrayList<>();
		for(int i = 0; i < n; i++) {
			a.add(scan.nextInt());
		}

		List<Integer> b = new ArrayList<>();
		b.add(k - a.get(n -1) + a.get(0));
		for(int i = 1; i < a.size(); i++) {
			b.add(a.get(i) - a.get(i -1));
		}

		System.out.println(k - Collections.max(b));
	}
}
