import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner((System.in));
		String n = sc.next();
		String ans = "No";

		if (n.contains("a") && n.contains("b") && n.contains("c")) {
			ans = "Yes";
		}

		System.out.println(ans);

		sc.close();
	}
}
