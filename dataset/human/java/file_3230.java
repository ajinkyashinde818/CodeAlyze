import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.next());
		sc.close();

		int a = N / 10;
		int b = N % 10;
		if(a != 9 && b != 9) {
			System.out.println("No");
		}else {
			System.out.println("Yes");
		}

	}
}
