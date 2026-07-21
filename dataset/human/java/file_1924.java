import java.util.*;
public class Main {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt();
		int G = sc.nextInt();
		int p[] = new int[D];
		int c[] = new int[D];
		for(int i = 0; i < D; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		int ans = Integer.MAX_VALUE;
		out : for (int i = 0; i < (Math.pow(2, D)); i++) {
			int temp_ans = 0;
			boolean flag[] = new boolean[D];
			Arrays.fill(flag, false);
			int sum = 0;
			for (int j = 0; j < D; j++) {
				if ((1&i>>j) == 1) {
					sum += p[j] * (j + 1) * 100;
					sum += c[j];
					flag[j] = true;
					temp_ans += p[j];
				}
			}
			if(sum >= G) {
				ans = Math.min(ans, temp_ans);
				continue out;
			}
			in : for(int j = 0; j < D; j++) {
				if(!flag[D - 1 - j]) {
					for(int k = 0; k < p[D - 1 - j]; k++) {
						sum += 100 * (D - j);
						temp_ans++;
						if(sum >= G) {
							ans = Math.min(ans, temp_ans);
							break in;
						}
					}
					break in;
				}
			}
		}
		System.out.println(ans);
	}
}
