import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		// 整数の入力
        int n = sc.nextInt();
        int m = sc.nextInt();
        int ten = sc.nextInt();
        int c[] = new int[n];
		int a[][] = new int[n][m];

        int count;
        int ans = 999999999;
        int check = 0;
        for(int i = 0; i < n;i++ ){
          c[i] = sc.nextInt();
            for(int j = 0; j < m;j++){
               a[i][j] = sc.nextInt();
            }
        }
      
        for(int i = 0;i < Math.pow(2,n);i++){
          check = 0;
          count = 0;
          int cost[] = new int[m];
          for(int j = 0; j < n;j++){
            if((i >> j & 1) == 1){
              count += c[j];
              for (int k = 0; k < m; k++) {
						cost[k] += a[j][k];
					}
            }
          }
          for(int j = 0;j < m ;j ++){
            if(cost[j] < ten){check = 1;}
          }
          if(check != 1){
            if(count < ans){
              ans = count;
            }
          }
        }
        if(ans == 999999999){
          System.out.println(-1);
        }else{
          System.out.println(ans);
        }
          
    }
}
