import java.util.*;
import java.util.function.*;
import java.math.*;
public class Main {
    public static void main(String[] args){
		Scanner s = new Scanner(System.in);
		int D = s.nextInt();
		int G = s.nextInt();
		int[] p = new int[D]; 
		int[] c = new int[D]; 
		for(int i = 0; i < D; i++) {
			p[i] = s.nextInt();
			c[i] = s.nextInt();
		}
		
		boolean[] complete = new boolean[D];
		int[][] score = new int[D][];
		for(int i = 0; i < D; i++) {
			score[i] = new int[p[i]];
			for(int j = 0; j < p[i]; j++) {
				score[i][j] = (100 * (i + 1)) * (j + 1) + (j == p[i] - 1 ? c[i] : 0);
			}
		}
		
		// 引数1：必要点数 戻り値：必要点数を取得するのに必要な問題数
		final BiFunction<Integer, boolean[], Integer> up = (i, fcomplete) -> {
			int count = 0;
			// 総問題数分繰り返す（1 ～ D 問）
			for(int j = D - 1; j > -1; j--) {
				if(fcomplete[j])
					continue;
				// j + 1 問目の問題をk問解いたときの点数をマイナスする
				for(int k = 1; k < p[j]; k++) {
					i -= 100 * (j + 1);
					count++;
					if(i <= 0) {
						return count;
					}
				}
			}
			return -1;
		};
		
		// 初期設定
		int result = Integer.MAX_VALUE;
		int candidate = 0;
		int count = 0;
		for(int i = 0; i < (1<<D); i++, count = 0, candidate = 0, complete = new boolean[D]) {
			// j = j + 1 問目の問題を解いたかいなか
			for(int j = 0; j < D; j++) {
				if(((i>>j)&1) == 1) {
					candidate += score[j][score[j].length - 1];
					count += p[j];
					complete[j] = true;
				}
			}
			int additinal = 0;
			if(candidate < G) {
				additinal = up.apply(G - candidate, complete);
				if(additinal == -1)
					continue;
			}
			result = Math.min(result, count + additinal);
		}
		
		System.out.println(result);
    }
}
