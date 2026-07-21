import java.util.Scanner;
import java.lang.Math;

class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int a = stdIn.nextInt();
		int b = stdIn.nextInt();
		int c = stdIn.nextInt();
		int k;
		if (c <= a + b + 1) {
			k = b + c;
		} else {
			k = a + 2 * b + 1;
		}
		System.out.println(k);
	}
}
