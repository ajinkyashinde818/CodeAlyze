import java.io.PrintWriter;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int s = sc.nextInt();
		sc.close();

		PrintWriter pw = new PrintWriter(System.out);
		StringBuilder sb = new StringBuilder();
		for (int i = 0; i < k; i++) {
			sb.append(s).append(' ');
		}
		int a = s + 1;
		if (s == 1000000000) {
			a = 1;
		}
		for (int i = k; i < n; i++) {
			sb.append(a).append(' ');
		}
		sb.deleteCharAt(sb.length() - 1);
		System.out.println(sb.toString());
		pw.flush();
	}
}
