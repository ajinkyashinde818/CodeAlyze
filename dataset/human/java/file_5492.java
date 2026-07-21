import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int x = scan.nextInt();
		String contest = "";
		if(x < 1200) {
			contest = "ABC";
		} else {
			contest = "ARC";
		}
		System.out.println(contest);
	}
}
