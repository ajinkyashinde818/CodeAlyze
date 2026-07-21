import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int R = s.nextInt();
		System.out.println(N >= 10? R: 100 * (10 - N) + R);
	}
}
