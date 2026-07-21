import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		int Z = 0;
		int count = 0;

		/* 3重for文だとTLE
		for(int i = 0; i <= K; i++) {
			for(int j = 0; j <= K; j++) {
				for(int k = 0; k <= K; k++) {
					if(i + j + k == S) {
						count++;
					}

				}
			}
		}

		System.out.println(count);
		*/

		for(int i = 0; i <= K; i++) {
			for(int j = 0; j <=K; j++) {
				Z = S - i - j;
				if(Z >= 0 && Z <= K) {
					count++;
				}
			}
		}

		System.out.println(count);
	}

}
