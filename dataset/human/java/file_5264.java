import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(true){
			int n = sc.nextInt();
			if(n==0)break;
			int[][] map = new int[n+1][n+1];
			String s = "";
			int max = 0;
			for(int i=1;i<=n;i++){
				s = sc.next();
				for(int j=1;j<=n;j++){
					if(s.codePointAt(j-1)==46){
						map[i][j] = Math.min(Math.min(map[i-1][j], map[i][j-1]), map[i-1][j-1])+1;
						if(max<map[i][j])max=map[i][j];
					}
				}
			}
			System.out.println(max);
		}
	
	}	
}
