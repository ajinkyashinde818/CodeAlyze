import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		
		String a = scan.nextLine();
		
		System.out.println(a.substring(0,a.length()-8));
		
	}

}
