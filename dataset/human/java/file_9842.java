import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int x = sc.nextInt();
		
		int[] c = new int[n];
		int[][] a = new int[n][m];
		
		for(int i = 0; i < n; i++) {
			c[i] = sc.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = sc.nextInt();
			}
		}
		
		// 用意
		int cost = 0;
		int[] aTemp = new int[m];
		boolean mastered = true;
		List<Integer> list = new ArrayList<>();
		
		// bit全探索
		for(int i = 0; i < 1 << n; i++) {
			
			// n冊それぞれ探索
			for(int j = 0; j < n; j++) {
				
				// check
				if((i >> j & 1) == 1) {
					
					for(int k = 0; k < m; k++) {
						aTemp[k] += a[j][k];
					}
					
					cost += c[j];
				}
				
			}
			
			// アルゴリズム理解度満たしているかチェック
			for(int j = 0; j < m; j++) {
				if(aTemp[j] < x) {
					mastered =false;
					break;
				}
			}
			
			
			// マスターしてればコストを一時格納
			if(mastered) {
				list.add(cost);
			}
			
			// 後始末
			for(int j = 0; j < m; j++) {
				aTemp[j] = 0;
			}
			cost = 0;
			mastered = true;
			
		}
		
		Collections.sort(list);
		
		if(list.size() == 0) System.out.println(-1);
		else System.out.println(list.get(0));
		
	}

}
