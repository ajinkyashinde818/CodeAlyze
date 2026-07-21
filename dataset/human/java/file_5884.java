import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		String message = "No";
		String[] a = new String[3];
		a[0] = s.charAt(0) + "";
		a[1] = s.charAt(1) + "";
		a[2] = s.charAt(2) + "";
		Arrays.sort(a);
		if("abc".equals(a[0] + a[1] + a[2])) {
			message = "Yes";
		}
		System.out.println(message);
	}
}
