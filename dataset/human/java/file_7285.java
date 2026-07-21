import java.util.*;
public class Main {
	public static void main(String[] args) {
		String S = new Scanner(System.in).next();
		S = S.replaceAll("eraser", "");
		S = S.replaceAll("erase", "");
		S = S.replaceAll("dreamer", "");
		S = S.replaceAll("dream", "");
		System.out.println(S.length() == 0 ? "YES" : "NO");
	}
}
