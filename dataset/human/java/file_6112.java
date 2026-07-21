import java.util.Scanner;

public class Main {
	int count = 0;
	void run() {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int S = sc.nextInt();
		for(int x = 0; x <= K; x++) {
			for(int y = 0; y <= K; y++) {
				if(S - x - y >= 0 && S - x - y <= K) {
					count++;
				}
			}
		}
		System.out.println(count);
		sc.close();
	}

	public static void main(String[] args) {
		new Main().run();
	}
}
