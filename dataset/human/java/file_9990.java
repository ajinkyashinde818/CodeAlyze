import java.util.*;
public class Main{
	public static void main(String[] args)
	{
		Scanner sc =new Scanner(System.in);
        int n = sc.nextInt(),m = sc.nextInt(),x = sc.nextInt();
        int[] c = new int[n];
        int[][] a = new int[n][m+1];
        for(int i=0;i<n;i++){
            for(int j =0;j<=m;j++){
                a[i][j]=sc.nextInt();
            }
        }
        int INF = 1001001001;
        int ans = INF;
        for(int i =1;i<(1<<n);i++){
            boolean f = true;
            int cost = 0;
            int[] skil = new int[m];
            for(int j =0;j<n;j++){
                if((1&(i>>j))==1){
                    cost += a[j][0];
                    for(int k = 0;k<m;k++){
                        skil[k]+=a[j][k+1];
                    }
                }
            }
            for(int j =0;j<m;j++){
                if(skil[j]<x){
                    f = false;
                }
            }
            if(f){
                ans = Math.min(ans,cost);
            }
        }
        if(ans==INF){
            System.out.println(-1);
        } else {
            System.out.println(ans);
        }
	}
}
