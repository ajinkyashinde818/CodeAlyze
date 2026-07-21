import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] ch = s.toCharArray();
		if (ch[0] != ch[1] && ch[1] != ch[2] && ch[0] != ch[2]) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
