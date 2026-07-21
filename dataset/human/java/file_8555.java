import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int K = scanner.nextInt();

		int gcd = gcd(A, B);
		int count = 0;
		int answer = 0;
		for(int i = 1;count < K ; i ++) {
			if(gcd % i == 0) {
				answer = gcd / i;
				count ++;
			}
		}

		System.out.println(answer);
	}

	static int gcd(int a, int b) {
		int temp;
		while ((temp = a % b) != 0) {
			a = b;
			b = temp;
		}
		return b;
	}
}
