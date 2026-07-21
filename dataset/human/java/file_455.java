import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int r = sc.nextInt();
		sc.close();
		if (n < 10) {
			int calibrate = 100 * (10 - n);
			r = r + calibrate;
		}
		print(r);
	}

	public static void print(Object obj) {
		System.out.println(obj);
	}

}
