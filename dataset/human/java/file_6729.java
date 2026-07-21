import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = sc.nextInt();
		int n = sc.nextInt();

		int saisyo = 0;
		int hozon = 0;
		int saidai = 0;
		int saigo = 0;

		for (int i = 0; i < n; i++) {
			int a = sc.nextInt();

			if (saidai < a - hozon) {
				saidai = a - hozon;
			}

			if (i == 0) {
				saisyo = a;
			}
			if (i == n - 1) {
				saigo = a;
			}

			hozon = a;
		}

		int kotae2 = k - saidai;
		int kotae3 = saigo - saisyo;

		if (kotae2 < kotae3) {
			System.out.println(kotae2);
		} else {
			System.out.println(kotae3);
		}

		sc.close();
	}

}
