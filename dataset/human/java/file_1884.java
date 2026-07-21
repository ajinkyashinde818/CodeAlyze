import java.util.Scanner;

public class Main {
	static int []p;
	static int []c;
	static int min;
	static int G;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int D = scan.nextInt();
		G = scan.nextInt() / 100;
		p = new int[D];
		c = new int[D];
		int num = 0;

		for(int i = 0; i < D; i++) {
			int t1 = scan.nextInt();
			int t2 = scan.nextInt() / 100;
			p[i] = t1;
			c[i] = t2;
			num += p[i];
		}
		scan.close();
		min = num;

		int []bit = new int[D];
		rec(0, D, bit);
		System.out.println(min);

	}
	static void rec(int k, int n, int[] S) {
        if(k == n) {
        	solve(S);
            return;
        }
        rec(k + 1, n, S);
        S[k] = 1;
        rec(k + 1,n, S);
        S[k] = 0;
    }
	static void solve(int[] S) {
		int point = 0;
		int cnt = 0;
		for(int i = 0; i < S.length; i++) {
			if(S[i] == 1) {
				point += p[i] * (i + 1) * 1 + c[i];
				cnt += p[i];
			}
		}
		if(point >= G) {
			if(min > cnt) {
				min = cnt;
			}
		}else {
			int res = G - point;
			for(int i = S.length - 1; i >= 0; i--) {
				if(S[i] == 0) {
					int t = (i + 1) * 1;
					int k = (int)Math.ceil((double)res / t);
					if(k <= p[i] - 1) {
						if(min > cnt + k) {
							min = cnt + k;
						}
					}
				}
			}
		}
	}
}
