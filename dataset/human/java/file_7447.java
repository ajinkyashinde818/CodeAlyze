import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static PrintStream so = System.out;
	public static void main(String[] args) throws InterruptedException {

		String s = sc.next();
		
		String[] a = {"dreameraser", "dreamerase", "dreamer", "dream", "eraser", "erase"};
		int idx = 0;
		
		outer: while (true) {
			for (String elem: a) {
				if (s.startsWith(elem, idx)) {
					idx += elem.length();
					if (idx == s.length()) {
						so.println("YES");
						return;
					}
					continue outer;
				}
			}
			
			so.println("NO");
			return;
		}
	}
}
