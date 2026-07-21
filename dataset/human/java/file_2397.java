import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String s = input.nextLine();
		System.out.println(s.substring(0, s.length() - 8));
	}
}
