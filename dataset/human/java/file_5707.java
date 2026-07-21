import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		char[] sArray = S.toCharArray();
		Arrays.sort(sArray);
		String ans = new String(sArray).equals("abc") ? "Yes" : "No";
		System.out.println(ans);
		sc.close();
	}
}
