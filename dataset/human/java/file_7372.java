import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String s = br.readLine();
		String str[] = s.split("");

		int now = str.length;
		for (int i = str.length; i >= 1;) {
			if (i - 7 >= 0) {
				String ss = s.substring(i - 7, i);
				if (ss.equals("dreamer")) {
					i -= 7;
					now = i;
					continue;
				}
			}
			if (i - 6 >= 0) {
				String ss = s.substring(i - 6, i);
				if (ss.equals("eraser")) {
					i -= 6;
					now = i;
					continue;
				}
			}
			if (i - 5 >= 0) {
				String ss = s.substring(i - 5, i);
				if (ss.equals("dream") || ss.equals("erase")) {
					i -= 5;
					now = i;
					continue;
				}
			}
			if (now == i) {
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}
}
