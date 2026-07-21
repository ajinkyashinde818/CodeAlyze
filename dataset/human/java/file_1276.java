import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int A[] = new int[N];
		long sum  =0;
		for (int i=0;i<N;i++) {
			A[i] = sc.nextInt();
			sum +=A[i];
		}
		long temp =0;
		long min = Long.MAX_VALUE;
		for (int i=0;i<N-1;i++) {
			temp+=A[i];
			sum -=A[i];
			if (Math.abs(temp-sum)<min) {
				min = Math.abs(temp-sum);
			}
		}
		System.out.print(min);
	}
}
