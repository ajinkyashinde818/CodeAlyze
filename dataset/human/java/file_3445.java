import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String n = sc.next();

		System.out.println(n.indexOf("9") == -1 ? "No" : "Yes");

		sc.close();

	}

}
