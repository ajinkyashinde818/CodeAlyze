import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		System.out.println(S.contains("a")&& S.contains("b") && S.contains("c") ? "Yes" : "No");
	}
}
