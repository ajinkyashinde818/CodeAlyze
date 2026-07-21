import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		new Main().run();
	}

	void run() {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		System.out.println(s.substring(0, s.length() - 8));
	}

	void tr(Object... objects) {
		System.out.println(Arrays.deepToString(objects));
	}

}
