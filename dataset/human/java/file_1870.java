import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);

		int D = scan.nextInt();
		int G = scan.nextInt();

		int[] p = new int[D];
		int[] c = new int[D];

		for (int input = 0; input < D; input++) {
			p[input] = scan.nextInt();
			c[input] = scan.nextInt();
		}

		int total;
		int positionCount;
		int numberOfProblems;
		int zeroposition;
		int min = (int)Math.pow(2, 30);

		for (int bit = 0; bit < Math.pow(2, D); bit++) {

			total = 0;
			positionCount = 0;
			numberOfProblems = 0;
			zeroposition = -1;

			for (int shift = 0; shift < D; shift++) {		//全ビット探索：1が+を入れることに対応

				if ((1&bit>>shift) == 1) {
					total += 100*(positionCount+1) * p[positionCount] + c[positionCount];
					numberOfProblems += p[positionCount];
				} else {
					zeroposition = positionCount;
				}

				positionCount++;

			}
				
			if (total < G) {
				if (100*(zeroposition+1)*(p[zeroposition]-1) >= G - total) {
					numberOfProblems += Math.ceil((double) (G - total) / (100*(zeroposition+1)));
				} else {
					continue;
				}
			}
			
			if (min > numberOfProblems) {
				min = numberOfProblems;
			}

		}

		System.out.println(min);

	}
}
