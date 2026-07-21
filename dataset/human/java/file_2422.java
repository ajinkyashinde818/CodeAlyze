import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		solve();
	}

	private static void solve() {
		try (Scanner cin = new Scanner(System.in)) {

			String s = cin.next();
			System.out.println(s.substring(0, s.lastIndexOf("FESTIVAL")));
		} finally {
		}
	}

}
