import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		long A[] = new long[N];
		for (int i = 0; i < N; i++) {
			A[i] = sc.nextLong();
		}
		int countMinus = 0;
		for (int i = 0; i < N; i++) {
			if (A[i] < 0) {
				countMinus++;
			}
		}
		long sum = 0;
		long min = Integer.MAX_VALUE;
		for (int i = 0; i < N; i++) {
			long abs = Math.abs(A[i]);
			if (abs < min) {
				min = abs;
			}
			sum +=abs;
		}
		if (countMinus%2==1) {
			sum -=min*2;
		}
		System.out.println(sum);
	}
}
