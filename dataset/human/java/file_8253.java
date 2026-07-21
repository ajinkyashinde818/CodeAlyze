import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();

		long minAB = Math.min(a, b);
		int i = 1;
		while (minAB * i / a <= 0
			|| minAB * i / b <= 0
			|| minAB * i % a != 0
			|| minAB * i % b != 0) {
			i++;
		}
		System.out.println(minAB * i);
		sc.close();
	}
}
