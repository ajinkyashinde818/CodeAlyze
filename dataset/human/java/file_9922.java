import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		int n = stdIn.nextInt(); //n冊
		int m = stdIn.nextInt(); //アルゴリズム数
		
		int x = stdIn.nextInt(); 
		
		int[] c = new int[n];
		
		int[][] a = new int[n][m];
		
		for(int i = 0; i < n; i++) {
			c[i] = stdIn.nextInt();
			for(int j = 0; j < m; j++) {
				a[i][j] = stdIn.nextInt();
			}
		}
      
		//まず達成可能か見る
		boolean flag = true;
		int min = Integer.MAX_VALUE;
		int boolcheck = 0;
					
Outer:	for(int bit = 0; bit < (1 << n); bit++) {
			int[] check = new int[m];
			int ans = 0;
			
			for(int j = 0; j < n; j++ ) {
				if(((bit>>j)&1)==1){
					ans += c[j];
					
					
					for(int k = 0; k < m; k++) {
						check[k]+= a[j][k];
					}
					
					
				}
				
				
			}
			
			for(int k = 0; k < m; k++) {
				if(check[k] < x) {
					boolcheck++;
					continue Outer;
				}
			}
			
			min = Math.min(ans, min);
			
			
			
		}
		
		if(boolcheck==(1<<n)) {
			System.out.println(-1);
		}else {
			System.out.println(min);
		}		
	}

}
