import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		String[] s = in.nextLine().split("");
		String[] t = in.nextLine().split("");
		
		Arrays.parallelSort(s);
		Arrays.parallelSort(t, Collections.reverseOrder());
		
		String newS = String.join("", s);
		String newT = String.join("", t);
		
		System.out.println(newS.compareTo(newT) < 0 ? "Yes" : "No");
		
		/*if (newS.equals(newT)) {
			System.out.println("No");
		} else {
			System.out.println(newS.compareTo(newT) <= 0 ? "Yes" : "No");
		}
		*/
	}

}
