import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();
		
		int ans = x.compareTo(y);
		if (ans > 0) {
			System.out.println(">");
		} else if (ans >= 0) {
			System.out.println("=");
		} else {
			System.out.println("<");
		}
	}
}
