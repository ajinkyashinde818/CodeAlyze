import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int A = sc.nextInt();
		int B = sc.nextInt();
		int C = sc.nextInt();

		int doku = 0;
		// 毒入クッキーを食べられる枚数
		if (C <= A+B+1) {
			doku = C;
		} else {
			doku = A+B+1;
		}

		System.out.println(B+doku);

	}
}
