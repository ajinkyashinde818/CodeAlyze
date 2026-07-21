import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String[] c = sc.next().split("");

		System.out.println(c[0].equals("9") || c[1].equals("9") ? "Yes" : "No");
	}
}
