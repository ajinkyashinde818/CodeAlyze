import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {
			
			int n = sc.nextInt();
			int m = sc.nextInt();
			int x = sc.nextInt();
			
			int[] costs = new int[n];
			int[][] bookPoints = new int[n][m];
			
			for(int i = 0 ; i < n ; i++ ) {
				costs[i] = sc.nextInt();
				for( int j = 0 ; j < m ; j++ ) {
					bookPoints[i][j] = sc.nextInt(); 
				}
			}
			
			int totalCost = Integer.MAX_VALUE;
						
			//bit n to index
			for(int i = 1 ; i < (int)Math.pow(2, n) ; i++ ) {

				int[] currentPoint = new int[m];
				int currentCost = 0;
//				System.out.println("--- i = " + i);
				for(int j = 0 ; j < n ; j++ ) {
					// calc bit mask
					int p = (i & (int)Math.pow(2,j)) >> j;
					if ( p == 1 ) {
						currentCost += costs[j];
						for(int k = 0 ; k < m ; k++ ) {
							currentPoint[k] += bookPoints[j][k];
						}
					}
				}
				
				//check points
				boolean clear = true;
				for(int k = 0 ; k < m ; k++ ) {
					if ( currentPoint[k] < x ) {
						clear = false;
						break;
					}
				}
				
				if ( clear ) {
					if ( currentCost < totalCost ) {
						totalCost = currentCost;
					}
				}
			}
			
			if ( totalCost == Integer.MAX_VALUE ) {
				System.out.println("-1");
			}
			else {
				System.out.println(totalCost);
			}
		}
	}

}
