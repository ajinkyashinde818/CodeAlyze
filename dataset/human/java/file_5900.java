import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] s = sc.next().toCharArray();
		
		Arrays.sort(s);
		if (String.valueOf(s).equals("abc")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
