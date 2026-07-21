import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String n = sc.next();
		String[] nl = n.split("");
		if (nl[0].equals("9") || nl[1].equals("9")) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
