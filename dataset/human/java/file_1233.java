import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		long[] sum = new long[n+1];
		for(int i = 0; i < n; i++){
		    long a = sc.nextLong();
		    sum[i+1] += sum[i] + a; 
		}
		
		// 計算
		long result = Long.MAX_VALUE;
		for(int i = 1; i < n; i++){
		    result = min(result, abs((sum[n] - sum[i]) - sum[i]));
		}
		
		// 出力
		System.out.println(result);
	}

}
