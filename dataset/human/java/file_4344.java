import java.util.Scanner;

public class Main {

	static Main instance = new Main();

	public static void main(String[] args) {

		Scanner scan = new Scanner(System.in);

		//入力値(N)
		int numN = scan.nextInt();

		//入力値(N)
		int[] listA = new int[numN];
		int[] listB = new int[numN];
		int[] listC = new int[numN-1];

		for (int i = 0; i < numN; i++) {
			listA[i] = scan.nextInt();
		}

		for (int i = 0; i < numN; i++) {
			listB[i] = scan.nextInt();
		}

		for (int i = 0; i < numN - 1; i++) {
			listC[i] = scan.nextInt();
		}

		int sum = 0;
		for (int i = 0; i < numN; i++) {
			sum += listB[i];
		}

		int extra = 0;
		for (int i = 0; i < numN - 1; i++) {
			if (listA[i+1] - listA[i] == 1) {
				extra += listC[listA[i] - 1];
			}
		}

		System.out.println(sum + extra);
	}
}
