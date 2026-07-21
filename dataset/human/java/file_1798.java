import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
	InputStream in = System.in;
	PrintStream out = System.out;

	// s点以上となる最小の問題数を返す。（u はiごとの問題数）
	int res(int[] u, int s) {
		int ans = 0;
		for(int i=D;i>=1;i--) {
			if(u[i]*i*100 >= s) {
				return ans + (int)Math.ceil((double)s/(i*100));
			}else {
				ans += u[i];
				s -= u[i]*i*100;
			}
		}
		//全部といてもsに届かない
		return Integer.MAX_VALUE;
	}
	
	// cmp[i]をコンプリートしたときの最小の問題数
	int res2(boolean[] cmp) {
		int ans = 0;
		int score = 0;
		//コンプリートした問題の点数の合計とコンプリートボーナス
		for(int i=1;i<=D;i++) {
			if(cmp[i]) {
				ans += p[i];
				score += p[i]*i*100 + c[i];
			}
		}
		
		if(score >= G) {
			return ans;
		}
		
		//それ以外の問題で最小の
		int[] np = new int[D+1];
		System.arraycopy(p, 0, np, 0, D+1);
		for(int i=1;i<=D;i++) {
			if(cmp[i]) {
				np[i] = 0;
			}
		}
		
		int r = res(np, G-score);
		return r ==Integer.MAX_VALUE ? r : ans + r;
		
	}
	
	int D,G;
	int[] p,c;
	public void _main(String[] args) {
		Scanner sc = new Scanner(in);

		D = sc.nextInt();
		G = sc.nextInt();
		
		p = new int[D+1];
		c = new int[D+1];
		
		for(int i=1;i<=D;i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}
		
		int ans = Integer.MAX_VALUE;
		
		for(int x=1;x<= 1<<(D+1);x++) {
			boolean[] cm = new boolean[D+1];
			for(int i=1;i<=D;i++) {
				cm[i] = ((x>>i &0x01) == 1);
			}
			ans = Math.min(ans, res2(cm));
		}
		
		out.println(ans);
		
		
		sc.close();

	}

	public static void main(String[] args) {
		new Main()._main(args);
	}

}
