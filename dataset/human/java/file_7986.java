import java.util.Scanner;

public class Main {


	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
		int b = sc.nextInt();

		long x = 1;
		long n = 0;
		while(true) {
			n = a * x;
			if(n % b == 0) {
				break;
			}
			x++;
		}

		System.out.println(n);

		sc.close();

	}

}
