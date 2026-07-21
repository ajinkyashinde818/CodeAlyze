import java.util.*;

public class Main {
    static long total = 0;
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] targets = new String[]{"dream", "dreamer", "erase", "eraser"};
		StringBuilder sb = new StringBuilder(sc.next());
		while (sb.length() > 0) {
		    boolean flag = false;
		    for (String s : targets) {
		        if (sb.length() >= s.length() && sb.lastIndexOf(s) == sb.length() - s.length()) {
		            flag = true;
		            sb.setLength(sb.length() - s.length());
		            break;
		        }
		    }
		    if (!flag) {
		        System.out.println("NO");
		        return;
		    }
		}
		System.out.println("YES");
	}
}
