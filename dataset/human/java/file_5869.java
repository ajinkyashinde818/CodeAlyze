import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		int cnt = 0;
		int a = 0;
		int b = 0;
		int c = 0;
		
		for (int i = 0; i < 3; i++) {
			if (s.charAt(i) == 'a') {
				a++;
			}
			if (s.charAt(i) == 'b') {
				b++;
			}
			if (s.charAt(i) == 'c') {
				c++;
			}
		}
		
		if (a == 1 && b == 1 && c == 1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
		scanner.close();

	}

}
