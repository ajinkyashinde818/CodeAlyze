import java.util.Scanner;

public class Main {
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		long a = scanner.nextLong();

		long b = scanner.nextLong();

		long x = a*b;

		if(a < b) {
			long temp = a;
			a = b;
			b = temp;

		}

		long r = a%b;

		while(r != 0) {
			a = b;
			b = r;
			r = a%b;
		}

		System.out.println(x/b);		

	}

}
