import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int d = sc.nextInt();
		int g = sc.nextInt();
		int[] p = new int[d];
		int[] c = new int[d];

		for(int i = 0;i < d;i++) {
			p[i] = sc.nextInt();
			c[i] = sc.nextInt();
		}

		int minNum = Integer.MAX_VALUE;
		for(int bit = 0;bit < (1 << d);bit++) {
			// bitが立っているp[i]に関して、すべての問題を解くという前提を置く
			int totalScore = 0;
			int tmpNum = 0;
			for(int i = 0;i < d;i++) {
				if(((bit >> i) & 1) == 1) {
					totalScore += ((i + 1) * 100) * p[i] + c[i];
					tmpNum += p[i];
				}
			}
			
			// スコアが足りない場合、bitが立っていないp[i]のうち、スコアが大きいものから一問ずつ解いていく
			if(totalScore < g) {
				for(int i = d - 1;i >= 0;i--) {
					if(((bit >> i) & 1) == 1) continue;
					for(int j = 0;j < p[i] - 1;j++) {
						totalScore += ((i + 1) * 100);
						tmpNum++;
						if(totalScore >= g) break;
					}
					
					if(totalScore >= g) break;
				}
			}
			
			if(totalScore >= g && tmpNum < minNum) minNum = tmpNum;
		}

		System.out.println(minNum);
	}
}
