import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;



public class Main {

	public static void main(String[] args) throws IOException {
		// TODO 自動生成されたメソッド・スタブ
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		String[] tmpArray = br.readLine().split(" ");

		int d = Integer.parseInt(tmpArray[0]);
		int g = Integer.parseInt(tmpArray[1]);


		int problem[] = new int[d];
		int bonus[] = new int[d];

		PriorityQueue<Integer> pq = new PriorityQueue<>();
		ProblemSet pset[] = new ProblemSet[d];
		for(int i = 0; i < d; i++){
			tmpArray = br.readLine().split(" ");

			problem[i] = Integer.parseInt(tmpArray[0]);
			bonus[i] = Integer.parseInt(tmpArray[1]);

			pset[i] = new ProblemSet((i + 1)*100, problem[i], bonus[i]);
		}

//		Arrays.sort(pset);
//
//		for(int i = 0; i < d; i++){
//			System.out.println(pset[i].point+" "+ pset[i].ave);
//		}

		//各ビットが1のとき、その問題はコンプしたことにする

		int minNum = Integer.MAX_VALUE;
		for(int i = 0; i < Math.pow(2, d); i++){
			boolean comp[] = new boolean[d];
			int bit = 1;
			for(int j = 0; j < d; j++){
				if((int)(bit & i) != 0){
					comp[j] = true;
				}

				bit <<= 1;
			}

			//debug
//			for(int j = 0; j < d; j++){
//				if(comp[j])System.out.println("comp "+(j + 1)*100);
//			}

			int tmpNum = 0;
			int tmpScore = 0;
			for(int j = 0; j < d; j++){
				if(comp[j]){
					tmpNum += problem[j];
					tmpScore += problem[j] * 100 * (j + 1) + bonus[j];
				}
			}

			//コンプ以外の問題は点数が高い順に
			for(int j = d - 1; j >= 0 && tmpScore < g ; j--){
				if(comp[j]){
					continue;
				}
				for(int k = 0; k < problem[j] - 1; k++){
					tmpNum++;
					tmpScore += (j + 1)*100;

					if(tmpScore >= g){
						break;
					}
				}
			}
//			System.out.println("tmpNum:" + tmpNum +" tmpScore: "+tmpScore);
			if(tmpScore >= g){
				minNum = Math.min(minNum, tmpNum);
			}
		}

		System.out.println(minNum);
	}

}

class ProblemSet implements Comparable<ProblemSet>{
	int num;
	int bonus;
	int point;
	double ave;

	ProblemSet (int point, int num, int bonus){
		this.point = point;
		this.num = num;
		this.bonus = bonus;

		ave = ((double)point * num + bonus)/num;
	}

	@Override
	public int compareTo(ProblemSet p) {
		// TODO 自動生成されたメソッド・スタブ

		if(this.ave > p.ave){
			return -1;
		}
		else if(this.ave == p.ave){
			return 0;
		}
		else {
			return 1;
		}
	}


}
