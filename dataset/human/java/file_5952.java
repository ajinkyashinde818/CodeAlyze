import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.next();
		if(input.indexOf('a') != -1 && input.indexOf('b') != -1 && input.indexOf('c') != -1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
