import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		long a = sc.nextInt();
		long b = sc.nextInt();
		int num = 1;
		
		while(true) {
					for(int i = 2; i <= 100000; i++) {
			if(a % i == 0  && b % i == 0) {
				a /= i;
				b /= i;
				num *= i;
				break;
			} else if (i == 100000) {
				System.out.println(a * b * num);
				return;
			}
		}
		}
	}
}
