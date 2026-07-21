import java.util.Arrays;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);

		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];

		for(int i=0; i<N; i++) {
			A[i] = sc.nextInt();
		}

		int[] amari = new int[N];

		for(int i=1; i<N; i++) {
			amari[i] = A[i] - A[i-1];
		}
		amari[0] = (K - A[N-1]) + A[0];

		Arrays.sort(amari);

		int ans = K - amari[N-1];

		System.out.println(ans);
	}

}
