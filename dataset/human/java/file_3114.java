import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int T = sc.nextInt();
		for(int z=0;z<T;z++){
			int n = sc.nextInt();
			String s = sc.next();
			boolean[][] map = new boolean[2][2*n+2];
			for(int i=1;i<=2*n;i++){
				if(s.charAt(i-1)=='Y') map[0][i] = true;
				if(s.charAt(i+2*n-1)=='Y') map[1][i] = true;
			}

			int[][] dp = new int[3][n+2];
			for(int i=0;i<3;i++) Arrays.fill(dp[i], Integer.MAX_VALUE);
			dp[0][0] = 0;
			
			boolean t, b;
			int add = 0;
			for(int k=0;k<=n;k++){
				for(int i=0;i<3;i++){
					for(int j=0;j<3;j++){
						if(k==0 && i==0 || k==n && j==0 || 0<k && k<n){
							t = map[0][2*k]|map[0][2*k+1];
							b = map[1][2*k]|map[1][2*k+1];
							if(i-j==2 || i-j==-2) add = 3;
							else if(i+j==1){
								if(b) add = 3;
								else add = 2;
							}
							else if(i+j==3){
								if(t) add = 3;
								else add = 2;
							}
							else{
								if(i==0 && b || i==2 && t) add = 4;
								else if(i==1 && t&b) add = 3;
								else if(t|b) add = 2;
								else add = 1;
							}
							
							dp[j][k+1] = Math.min(dp[j][k+1], dp[i][k]+add);
						}
					}
				}
			}
			System.out.println(dp[0][n+1]-1);
		}
	}

}
