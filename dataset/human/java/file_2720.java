import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		String[] sArray = s.split("");
		String[] tArray = t.split("");
		Arrays.sort(sArray);
		Arrays.sort(tArray, Comparator.reverseOrder());
		System.out.println(String.join("", sArray).compareTo(String.join("", tArray)) < 0 ? "Yes" : "No");
		sc.close();
	}
}
