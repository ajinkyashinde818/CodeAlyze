import java.util.Scanner;

//AtCoder Beginner Contest 120
//B	K-th Common Divisor
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();

		sc.close();

		int ret = 0;
		int x = 0;
		for (int i = 100; i >= 0; i--) {
			if (A % i == 0 && B % i == 0) {
				ret = i;
				x++;
				if (x == K) {
					break;
				}
			}
		}

		System.out.print(ret);
	}
}
