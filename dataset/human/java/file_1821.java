import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();//nanido
		int g = sc.nextInt();//mokuhyou
		int p[] = new int[d];//point
		int c[] = new int[d];//comp point
		int cnt = 0;//mondaisu
		int cntmin = 0;
		int sum = 0;
		for (int i = 0; i < d; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		for (int bit = 0; bit < (1 << d); bit++) {
			for (int i = 0; i < d; i++) {
				if ((bit & (1 << i)) != 0) {
					sum += p[i] * 100 * (i + 1) + c[i];
					cnt += p[i];
				}
			}
			for (int i = d - 1; i >= 0; i--) {
				if ((bit & (1 << i)) == 0) {
					for (int j = 0; j < p[i] - 1; j++) {
						if (sum >= g) {
							break;
						} else {
							sum += 100 * (i + 1);
							cnt++;
						}
					}
				}
			}
			if (sum >= g && (cntmin == 0 || cnt < cntmin)) {
				cntmin = cnt;
			}
			//System.out.println(cnt);
			cnt = 0;
			sum = 0;
		}
		System.out.println(cntmin);
	}
}
