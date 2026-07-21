import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		// ------------------------------------------------
		int n = Integer.parseInt(sc.next());
		ArrayList<Integer> a = new ArrayList<Integer>();
		ArrayList<Integer> b = new ArrayList<Integer>();
		ArrayList<Integer> c = new ArrayList<Integer>();
		for (int i = 0; i < n; i++) {
			a.add(Integer.parseInt(sc.next()) - 1);
		}
		for (int i = 0; i < n; i++) {
			b.add(Integer.parseInt(sc.next()));
		}
		for (int i = 0; i < n - 1; i++) {
			c.add(Integer.parseInt(sc.next()));
		}
		int pre = -999;
		int ret = 0;
		for (int i = 0; i < n; i++) {
			ret += b.get(a.get(i));
			if (pre == a.get(i) - 1) {
				ret += c.get(pre);
			}
			pre = a.get(i);
		}
		out.println(ret);

		// ------------------------------------------------
		sc.close();
		out.flush();
	}
}
