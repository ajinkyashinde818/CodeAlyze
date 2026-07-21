import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong();
		if((n + 2 )% 2 == 1) {
			System.out.println(0);
          return;
		}
		long count = 0;
		for(long i = 10 ; i <= n ; i *= 5) {
			count += n / i;
		}

		sc.close();
		System.out.println(count);

	}
}
