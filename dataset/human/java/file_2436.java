import java.util.*;
//atCoder用
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder ans = new StringBuilder (sc.next());
		int len = ans.length() - "FESTIVAL".length();
		System.out.println(ans.substring(0, len));
	}
}
