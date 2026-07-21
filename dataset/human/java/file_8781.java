import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int A = scanner.nextInt();
		int B = scanner.nextInt();
		int K = scanner.nextInt();

		int cnt = 0;
		int i = Math.max(A, B);

		while(true) {
			if(A%i==0 && B%i==0) {
				cnt ++;
			}
			if(K == cnt)
				break;

			i--;
		}

		System.out.println(i);

	}

}
