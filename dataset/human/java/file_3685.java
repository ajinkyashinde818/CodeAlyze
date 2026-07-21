import java.util.Scanner;

public class Main {

	public static void main(String... nui) {

		Scanner sc = new Scanner(System.in);

		char c = sc.next().charAt(0);
		char h = sc.next().charAt(0);
		
		System.out.println((c < h) ? "<" : (c > h) ? ">" : "=");
		
	}

}
