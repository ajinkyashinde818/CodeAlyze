import java.io.PrintWriter;
import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
      	Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		String S = new StringBuffer(sc.next()).reverse().toString();
		boolean flg = false;

		String[] keywords = {"maerd", "remaerd", "esare", "resare"};
		int currentI = 0;
		while (true) {
			for (String keyword: keywords) {
				int index = S.indexOf(keyword, currentI);
				if (index == currentI) {
					currentI += keyword.length();
					flg = true;
					break;
				}
			}

			if (currentI == S.length()) {
				out.println("YES");
				break;
			}

			if (flg) {
				flg = false;
			} else {
				out.println("NO");
				break;
			}
		}

		out.flush();
	}
}
