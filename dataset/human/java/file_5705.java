import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.nextLine();
		if(str.indexOf("a") != -1 &&
		   str.indexOf("b") != -1 &&
		   str.indexOf("c") != -1) {
			System.out.println("Yes");
			return;
		}
		System.out.println("No");
	}
}
