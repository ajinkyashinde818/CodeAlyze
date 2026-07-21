import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = sc.nextInt();
		int m = sc.nextInt();
		
		int[][] ships = new int[m][2];
		boolean[][] isExist = new boolean[n][2];
		
		for(int i=0; i<ships.length; i++) {
			ships[i][0] = sc.nextInt();
			ships[i][1] = sc.nextInt();
			
			if(ships[i][0]==1) {
				isExist[ships[i][1]][0] = true;
			}
			
			if(ships[i][1]==n) {
				isExist[ships[i][0]][1] = true;
			}
		}
		sc.close();
		
		boolean ans = false;
		
		for(boolean[] exist: isExist) {
			if(exist[0] && exist[1]) {
				ans = true;
				break;
			}
		}
		
		if(ans) {
			System.out.println("POSSIBLE");
		}else {
			System.out.println("IMPOSSIBLE");
		}
		
		

	}

}
