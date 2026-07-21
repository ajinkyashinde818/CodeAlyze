import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		sc.close();

		System.out.println(r + Math.max(10 - n, 0) * 100);
	}
}
