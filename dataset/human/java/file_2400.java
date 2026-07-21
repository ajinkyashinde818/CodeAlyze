import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String l = sc.nextLine();
		System.out.println(l.substring(0, l.length()-8));
		sc.close();
	}
}
