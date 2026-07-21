import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		
		int a = 0;
		int b = 0;
		int c = 0;
		
		for(int i = 0; i < 3; i++) {
			if(S.charAt(i) == 'a') {
				a++;
			} else if(S.charAt(i) == 'b') {
				b++;
			} else {
				c++;
			}
		}
		if(a == 1 && b == 1 && c == 1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
