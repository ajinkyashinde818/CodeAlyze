import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		List<String> sl = Arrays.asList(s.split(""));
		List<String> tl = Arrays.asList(t.split(""));
		Collections.sort(sl);
		Collections.sort(tl);
		Collections.reverse(tl);
		boolean able = false;
		for (int i = 0; i < ((sl.size() <= tl.size())? sl.size() : tl.size()); i++) {
			if (sl.get(i).compareTo(tl.get(i)) < 0) {
				able =true;
				break;
			}
			else if (sl.get(i).compareTo(tl.get(i)) > 0) {
				break;
			}
			else if (sl.size() < tl.size() && i == sl.size() - 1) {
				able = true;
			}
		}
		System.out.println((able)? "Yes" : "No");
	}
}
