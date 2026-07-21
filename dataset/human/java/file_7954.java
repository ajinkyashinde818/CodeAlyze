import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static int dfs(int n, int limit, int k, boolean[] is_prime, int[][][] memo){
		if(n < 0){
			return 0;
		}else if(memo[k][limit][n] >= 0){
			return memo[k][limit][n];
		}else if(k == 0 && n == 0){
			return 1;
		}else if(k == 0){
			return 0;
		}
		
		int ans = 0;
		//System.out.println(n + " " + limit);
		for(int prime = Math.min(n, limit - 1); prime >= 2; prime--){
			if(!is_prime[prime]){
				continue;
			}
			
			ans += dfs(n - prime, prime, k - 1, is_prime, memo);
		}
		
		return memo[k][limit][n] = ans;
	}
	
	public static final int MAX = 1120;
	public static final int SQRT = (int)(Math.ceil(Math.sqrt(MAX)));
	
	public static void main(String[] args) {
		final Scanner sc = new Scanner(System.in);

		boolean[] is_prime = new boolean[MAX + 1];
		
		for(int i = 2; i <= MAX; i++){
			is_prime[i] = true;
		}
		
		for(int i = 2; i <= SQRT; i++){
			if(is_prime[i]){
				for(int j = 2 * i; j <= MAX; j += i){
					is_prime[j] = false;
				}
			}
		}
		
		int[][][] memo = new int[15][MAX+2][MAX+1];
		
		for(int i = 0; i <= 14; i++){
			for(int j = 0; j <= MAX + 1; j++){
				Arrays.fill(memo[i][j], -1);
			}
		}
		
		while(true){
			final int n = sc.nextInt();
			final int k = sc.nextInt();
			
			if(n == 0 && k == 0){
				break;
			}
			
			System.out.println(dfs(n, n + 1, k, is_prime, memo));
		}
		
	}

}
