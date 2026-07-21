import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner kb = new Scanner(System.in);
		long a = kb.nextInt();
		long b = kb.nextInt();
		long gcd = 1;

		for (int i = 1; i <= a && i <= b; ++i) {
			// Checks if i is factor of both integers
			if (a % i == 0 && b % i == 0)
				gcd = i;
		}

		System.out.println(a * b / gcd);
		kb.close();
	}

}
