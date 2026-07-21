import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		int q = scanner.nextInt();

		List<String> before = new ArrayList<String>();
		List<String> after = new ArrayList<String>(Arrays.asList(s.split("")));

		boolean normal = true;
		boolean f;
		String c;
		for (int i = 0; i < q; i++) {
			if (scanner.nextInt() == 2) {
				f = scanner.nextInt() == 1;
				c = scanner.next();
				if (normal == f)
					before.add(c);
				else
					after.add(c);
			} else
				normal = !normal;
		}

		if (normal) {
			Collections.reverse(before);
			System.out.println(String.join("", before) + String.join("", after));
		} else {
			Collections.reverse(after);
			System.out.println(String.join("", after) + String.join("", before));
		}

	}

}
