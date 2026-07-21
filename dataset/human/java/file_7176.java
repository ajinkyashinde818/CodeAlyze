import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int k = sc.nextInt();
		int n = sc.nextInt();
		int[] a = new int[n];
		int sum = 0;
		for(int i = 0; i < n; i++){
		    a[i] = sc.nextInt();
		}
		
		// 計算
		int result = 0;
		int max = 0;
		for(int i = 1; i < n; i++){
		    max = max(max, a[i] - a[i-1]);
		}
		max = max(max, a[0] + k - a[n-1]);
		result = k - max;
		
		// 出力
		System.out.println(result);
	}
}
