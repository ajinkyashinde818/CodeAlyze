import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int K = s.nextInt();
		int S = s.nextInt();

		int answer = 0;
		for (int x = 0; x <= K; x++) {
			if (x > S)
				break;
			for (int y = 0; y <= K; y++) {
				if (x + y > S)
					break;

				int z = S - x - y;
				if(z<=K) {
					answer ++;
				}
				/*
				for (int z = 0; z <= K; z++) {
					if (x + y + z > S)
						break;

					if(x+y+z == S) {
						answer++;
					}

				}
				*/
			}
		}

		System.out.println(answer);

	}

}
