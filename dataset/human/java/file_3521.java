import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		if (a.compareTo(b) < 0)
			System.out.println("<");
		else if (a.compareTo(b) == 0)
			System.out.println("=");
		else
			System.out.println(">");
		sc.close();
	}
}
