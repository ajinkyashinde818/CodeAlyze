import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan=new Scanner(System.in);
		String n=scan.nextLine();
		if(n.contains("9")) {
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
