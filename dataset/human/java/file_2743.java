import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String[] s = sc.nextLine().split("");
		String[] t = sc.nextLine().split("");

		Arrays.sort(s);
		Arrays.sort(t, (o1, o2) -> {return o2.compareTo(o1);});

		String sAsc = String.join("", s);
		String tDesc = String.join("", t);

		if (sAsc.compareTo(tDesc) < 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
		sc.close();
	}
}
