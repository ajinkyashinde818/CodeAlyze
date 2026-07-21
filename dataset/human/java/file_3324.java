import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int n;
		n = sc.nextInt();
		sc.close();
		int r = n % 10;
		int r2 = n / 10;
		if (r != 9 && r2 != 9)
			System.out.println("No");
		else
			System.out.println("Yes");
	}

}
