import java.util.*;

public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		final int D = sc.nextInt();
		final int G = sc.nextInt();
		
		int p[] = new int[D];
		int c[] = new int[D];
		for(int i = 0; i < D; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		int answer = Integer.MAX_VALUE;
		boolean flag[] = new boolean[D];
		for(int i = 0; i < Math.pow(2, D); i++) {
			Arrays.fill(flag, true);
			int score = 0;
			int cnt = 0;
			for(int j = 0; j < D; j++) {
				if((1 & i >> j) == 1) {
					score += p[j] * (j + 1) * 100 + c[j];
					cnt += p[j];
					flag[j] = false;
				}
			}
			while(score < G) {
				boolean end_flag = false;
				if(score >= G) {
					break;
				}
				for(int k = D - 1; k >= 0; k--) {
					if(flag[k]) {
						int n = 0;
						while(n != p[k] && score < G) {
							score += (k + 1) * 100;
							cnt++;
							n++;
							if(n == p[k]) {
								score += c[k];
								flag[k] = false;
							}
						}
					}
					if(score >= G) break;
				}
			}
			answer = Math.min(answer, cnt);
		}
		System.out.println(answer);
	}
}
