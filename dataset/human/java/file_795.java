import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int r = scan.nextInt();
		scan.close();
		System.out.println((n<10)? r+100*(10-n):r);
	}
}
