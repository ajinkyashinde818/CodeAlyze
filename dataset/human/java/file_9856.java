import java.util.*;


import java.io.*;

public class Main {
    
    static long solve(int[] cost, int[][] points, int[] bucket, int x, int book){
        
        if(book >= cost.length){
            for(int i = 0; i < bucket.length; i++){
                if(bucket[i] < x){
                    return Long.MAX_VALUE;
                }
               
            }
            return 0;
        }
            
      
        long ans =  Long.MAX_VALUE;
        // leave current book
        long small = solve(cost, points, bucket, x, book+1);
        if(small != Long.MAX_VALUE)
            ans= Math.min(ans,small);
        
        int[] copy = bucket.clone();
        for(int i = 0; i < bucket.length; i++){
            copy[i] += points[book][i]; 
        }

     small = solve(cost, points, copy, x, book+1);
        if(small != Long.MAX_VALUE){
            ans = Math.min(ans,cost[book] + small); 
    
        }
        
        return ans;
    }
    

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in[] = br.readLine().trim().split(" ");
        int n = Integer.parseInt(in[0]);
        int m = Integer.parseInt(in[1]);
        int x = Integer.parseInt(in[2]);
        int bucket[] = new int[m];
      
        StringTokenizer token;
        int[] cost = new int[n];
        
        int[][] points = new int[n][m];
        for(int i = 0; i < n; i++){
            token =  new StringTokenizer(br.readLine().trim()," ");
            cost[i] = Integer.parseInt(token.nextToken());
            for(int j = 0; j < m; j++){
                points[i][j] = Integer.parseInt(token.nextToken());
            }
        }

        long ans = solve(cost, points, bucket, x, 0);
        if(ans == Long.MAX_VALUE)  System.out.println(-1); else System.out.println(ans);
    
    }
}
