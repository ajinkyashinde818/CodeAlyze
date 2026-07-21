import java.util.*;
import java.io.*;
public class Main
{
    public static long solve(int[][] level, int[] bucket, int[] cost, int i, int x){
        if(i >= cost.length){
            for(int j = 0; j < bucket.length; j++){
                if(bucket[j] < x){
                    return Long.MAX_VALUE;
                }
            }
            return 0;
        }
        long ans = Long.MAX_VALUE;
        long op1 = solve(level, bucket, cost, i+1, x);
        if(op1 != Long.MAX_VALUE){
            ans = Math.min(ans, op1);
        }
        int[] copy = bucket.clone();
        for(int j = 0; j < bucket.length; j++){
            copy[j] += level[i][j];
        }
        op1 = solve(level, copy, cost, i+1, x);
        if(op1 != Long.MAX_VALUE){
            ans = Math.min(ans, cost[i] + op1);
        }
        return ans;
    }
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] s = br.readLine().trim().split(" ");
		int n = Integer.parseInt(s[0]);
		int m = Integer.parseInt(s[1]);
		int x = Integer.parseInt(s[2]);
		int[] cost = new int[n];
		int[] bucket = new int[m];
		int[][] level = new int[n][m];
		for(int i = 0; i < n; i++){
		    String[] str = br.readLine().trim().split(" ");
		    cost[i] = Integer.parseInt(str[0]);
		    for(int j = 0; j < m; j++){
		        level[i][j] = Integer.parseInt(str[j+1]);
		    }
		}
		long ans = solve(level, bucket, cost, 0, x);
		if(ans != Long.MAX_VALUE){
		    System.out.println(ans);
		}
		else{
		    System.out.println(-1);
		}
	}
}
