import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int merry[] = {1, 4, 1, 4, 1, 2, 1, 2};
		int passenger[];
		int sum, max;
		int digitSum, digitMin;
		int digit;

		passenger = new int[8];
		while (sc.hasNext()) {
			max = 0;
			digitMin = 100000000;
			digit = 0;
			for (int i = 0; i < 8; i++) {
				passenger[i] = sc.nextInt();
			}
			for (int i = 0; i < 8; i++) {
				sum = 0;
				digitSum = 0;
				int k = 10000000;
				for (int j = 0; j < 8; j++) {
					sum += (merry[j] <= passenger[j]) ? merry[j] : passenger[j];
					digitSum += merry[j] * k;
					k /= 10;
				}
				if ((max < sum) || (max == sum && digitSum < digitMin)) {
					max = sum;
					digit = i;
					digitMin = digitSum;
				}
				int swap = merry[0];
				for (int j = 0; j < 7; j++) {
					merry[j] = merry[j + 1];
				}
				merry[7] = swap;
			}
			String s = "";
			for (int i = 0; i < 8; i++) {
				System.out.print(s + merry[(digit + i) % 8]);
				s = " ";
			}
			System.out.println();
		}
	}
}
