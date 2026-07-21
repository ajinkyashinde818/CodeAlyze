import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		try (Scanner scn = new Scanner(System.in)) {
			int N = scn.nextInt();
			long K = scn.nextLong();
			int[] A =  new int[N];
			int[] flg = new int[N];

			for(int i = 0; i < N; i++) {
				A[i] = scn.nextInt();
			}

			int cnt = 0;
			int next = 1;
			int prev = -1;
			for(int i = 0; i < K; i++) {
				flg[next-1]++;
				prev = next;
				next = A[next-1];
				cnt++;
				if(flg[next-1] == 2) {
					break;
				}
			}

			if(cnt == K) {
				System.out.println(next);
				System.exit(0);
			}
			//循環成立
			long tmp = 0;
			for(int i = 0; i < N; i++) {
				if (flg[i] == 2) tmp++;
			}

			long tmpK = (K - (long) cnt) % tmp;

			for(int i = 0; i < tmpK; i++) {
				flg[next-1]++;
				prev = next;
				next = A[next-1];
			}
			System.out.println(next);
		}
	}
}
