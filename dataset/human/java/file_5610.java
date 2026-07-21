import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner scn = new Scanner(System.in);
		int N = scn.nextInt(), K = scn.nextInt(), S = scn.nextInt();
		int MAX = 1000000000;
		int[] ans = new int[N];
		if (S == MAX) {
			for (int i = 0; i < N; i++) {
				if (K > 0) {
					ans[i] = S;
					K--;
				} else {
					ans[i] = S-1;
				}
			}
		} else {
			for (int i = 0; i < N; i++) {
				if (K > 0) {
					ans[i] = S;
					K--;
				} else {
					ans[i] = MAX;
				}
			}
		}
		printArrayLine(ans);
	}

	static void printArrayLine(int[] a) {
		int N = a.length;
		for (int i = 0; i < N; i++) {
			System.out.print(a[i] + ((i == N - 1) ? "\n" : " "));
		}
	}

}
