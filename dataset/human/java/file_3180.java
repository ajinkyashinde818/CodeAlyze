import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String N = sc.next();
		String ans = "Yes";

		if(N.contains("9")) {
			ans = "Yes";
		} else {
			ans = "No";
		}

		System.out.println(ans);
	}
}
