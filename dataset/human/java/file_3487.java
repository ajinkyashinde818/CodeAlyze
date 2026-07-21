import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		// 整数の入力
		String a = sc.next();
		String b = sc.next();

		int x = Integer.parseInt(a, 16);
		int y = Integer.parseInt(b, 16);

		if(x<y) {
			System.out.println("<");
		}else if(x>y) {
			System.out.println(">");
		}else {
			System.out.println("=");
		}
	}
}
