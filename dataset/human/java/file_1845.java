import java.util.Scanner;

class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int D = sc.nextInt(), G = sc.nextInt();
		long[] p = new long[D]; long[] c = new long[D];
		for(int i = 0; i < D; i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		/* コンプリートする問題の組み合わせを全列挙して、Greedyに問題を解く */
		long ans = Long.MAX_VALUE;
		for(int S = 0; S < (1<<D); S++) {
			// コンプリートする問題の組み合わせがSのとき
			long score = 0, solved = 0;
			// コンプリートする問題は全部とく
			for(int i = 0; i < D; i++) {
				if(((S >> i) & 1) == 1) {
					score += c[i] + p[i] * (long)(100 * (i + 1));
					solved += p[i];
				}
			}
			if(score >= G) {
				ans = Math.min(ans, solved);
				continue;
			}
			// コンプリートしてもまだ足りない時 -> コンプリートしてないやつの上から順に解いていく
			for(int i = D - 1; i >= 0; i--) {
				if(((S >> i) & 1) == 0) {
					// コンプリートしてないやつ
					long prob = p[i];
					while(prob > 1 && score < G) {
						prob--;
						score += 100 * (i + 1);
						solved++;
					}
				}
				if(score >= G) {
					ans = Math.min(ans, solved);
					break;
				}
			}
		}
		System.out.println(ans);
	}
}
