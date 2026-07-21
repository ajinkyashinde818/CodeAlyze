import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		sc.close();

		List<String> list = new ArrayList<>();
		String just = String.valueOf(s);
		for (int i = 0; i < k; i++) {
			list.add(just);
		}
		String string = String.valueOf(s - 1);
		if (s == 1 || s == 2) {
			string = "10";
		}
		for (int i = 0; i < n - k; i++) {
			list.add(string);
		}
		System.out.println(String.join(" ", list));
	}
}
