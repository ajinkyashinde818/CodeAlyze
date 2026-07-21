import java.util.*;
import static java.lang.Math.*;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int d = sc.nextInt();
		int g = sc.nextInt();
		int[][] pc = new int[d][2];
		for(int i = 0; i < d; i++){
		    pc[i][0] = sc.nextInt();
		    pc[i][1] = sc.nextInt();
		}
		
		// 計算
		int result = Integer.MAX_VALUE;
		for(int i = 0; i < 1<<d; i++){
		    int score = 0;
		    int cnt = 0;
		    int[] used = new int[d];
		    for(int j = 0; j < d; j++){
		        if((1 & i>>j) == 1){
		            score += (j+1)*100 * pc[j][0] + pc[j][1];
		            cnt += pc[j][0];
		            used[j] = 1;
		        }
		    }
		    for(int j = d-1; j >= 0; j--){
		        if(score >= g) break;
		        if(used[j] == 0){
		            for(int k = 0; k < pc[j][0] - 1; k++){
		                if(score >= g) break;
		                score += (j+1)*100;
		                cnt++;
		            }
		            break;
		        }
		    }
		    if(score >= g) result = min(result, cnt);
		}
		
		// 出力
		System.out.println(result);
	}
}
