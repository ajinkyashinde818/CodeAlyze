import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		int ans = 0;
//
		if (K * 3 == S) {
			System.out.println("1");
			System.exit(0);
		}
//
		if (K == S) {
			System.out.println(K * 3);
			System.exit(0);
		}

		for (int x = 0; x <= K; x++) {
			for (int y = 0; y <= K; y++) {
//				for (int z = 0; z <= K; z++) {
					if (S - (x + y) <= K && S - (x + y) >= 0) {
						ans++;
					}


//				}
			}
		}





		System.out.println(ans);


		sc.close();
	}


}
