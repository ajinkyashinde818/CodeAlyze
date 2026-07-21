import java.util.Scanner;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		String ans = s.substring(0, s.length() - 8);

		System.out.println(ans);

		sc.close();
	}

}
