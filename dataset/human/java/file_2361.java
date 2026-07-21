import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String str = scan.next();
		int l =str.length();
		System.out.println(str.substring(0, l-8));
	}
}
