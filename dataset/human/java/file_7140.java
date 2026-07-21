import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int K = sc.nextInt();
		int N = sc.nextInt();
		int[] A = new int[N];
		for(int i = 0; i < N; i++) {
			A[i] = sc.nextInt();
		}

		int[] dis = new int[N];
		dis[0] = K - A[N-1] + A[0];
		for(int i = 1; i < N; i++) {
			dis[i] = A[i] - A[i-1];
		}

		int maxDis = 0;
		for(int i = 0; i < N; i++) {
			if(dis[i] >= maxDis) {
				maxDis = dis[i];
			}
		}
		System.out.println(K - maxDis);
		sc.close();
	}
}
