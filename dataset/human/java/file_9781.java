import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int M = s.nextInt();
		int X = s.nextInt();
		int[][] A = new int[N][M];
		int[] C = new int[N];
		
		for(int i=0; i<N; i++) {
			C[i] = s.nextInt();
			for(int k=0; k<M; k++) {
				A[i][k] =s.nextInt();
			}
		}
		ArrayList<Integer> sum_Cs = new ArrayList<Integer>();
		for(int i=0; i< 1<<N; i++) {
			int sum_C =0; //探索一回ごとの購入した参考書の金額の総計
			boolean skillcheck = true;
			int[] myP = new int[M]; //得た能力値の総計
			
			for(int j=0; j<N; j++) {
				if((1 & i>>j ) == 1) { //j番目の参考書が条件を満たすのなら、参考書購入
					sum_C += C[j]; //金額を足す
					for(int k=0; k<M; k++) {  //参考書から能力を得る
						myP[k] += A[j][k];
					}
					
				}
			}
			for(int j=0; j<M; j++) { //全ての能力値がXを満たしているか判定
				if(myP[j] <X) {skillcheck = false; break;}
			}
			if(skillcheck) { //全ての能力値を満たしているのでリストに今回の探索の結果得られた金額を追加
				sum_Cs.add(sum_C);
			}
				
		}
		int ans =0;
		if(sum_Cs.size() == 0) {ans =-1;}
		else {
			Collections.sort(sum_Cs);
			ans = sum_Cs.get(0);
		}
		
		System.out.println(ans);
		
		
		
	}

}
