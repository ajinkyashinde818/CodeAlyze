import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		int n = in.nextInt(), goal = in.nextInt();
		Problem[] p = new Problem[n];
		for (int i=0; i<n; i++) {
			p[i] = new Problem(in.nextLong(), (i+1)*100, in.nextLong());
		}

		//ビット全探索+@
		long min = Long.MAX_VALUE;
		for (int i=0; i<(1<<n); i++) {

			int num = 0; //その組み合わせでは何問解いたか？
			long sum = 0L; //その組み合わせで得られたスコアの合計

			//全完していない問題のうち、最もスコアが高いもの、すなわち
			//i をビット表現したときに最も右側にある 0 の位置を記録する変数
			int rightMost = -1;

			for (int j=n-1; j>=0; j--) { //
				if ((1&i>>j) == 1) {
					sum += p[j].num * p[j].score + p[j].bonus;
					num += p[j].num;
				}
				else if ((1&i>>j) == 0 && rightMost == -1) {
					rightMost = j;
				}
			}

			//sum が目標スコア以上の場合は、解いた問題の数をそのまま min に記録する
			if (sum >= goal) {
				min = Math.min(min, num);
				continue;
			}
			else if (rightMost != -1){
				//そうでない場合かつ、全完していない問題が少なくとも1つある場合

				//目標スコアに届くまで、スコアが最も多い問題を needNum 回解く必要がある
				long needNum = (goal-sum+p[rightMost].score-1) / p[rightMost].score;

				if (needNum > p[rightMost].num) {
					//スコアが最も多い問題が needNum 問より少ないなら、放棄
					continue;
				}
				else {
					//そうでないなら、スコアが最も多い問題を needNum 問解き、
					//min を更新する
					min = Math.min(min, num + needNum);
				}
			}

		}

		System.out.println(min);

	}

	static class Problem {
		long num, score, bonus;
		Problem (long a, long b, long c) {
			num = a; score = b; bonus = c;
		}
	}


}
