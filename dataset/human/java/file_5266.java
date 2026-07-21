//Volume0-0092
import java.util.Scanner;

public class Main {

	//declare
	private static int      n;
	private static int [][] dp;
	private static char[][] board;

	public static void main(String[] args) {

        //input
        Scanner sc = new Scanner(System.in);
        while((n = Integer.parseInt(sc.nextLine())) != 0){
        	board = new char[n][n];
        	dp    = new int [n][n];
        	for(int i=0;i<n;i++){
        		board[i] = sc.nextLine().toCharArray();
        	}

        	//calculate
        	int max = 0;
        	for(int i=0;i<n;i++){
        		for(int j=0;j<n;j++){
        			if(board[i][j] == '*'){dp[i][j] = 0; continue;}
        			if(i == 0 || j == 0)  {dp[i][j] = 1; continue;}
        			dp[i][j] = Math.min(dp[i-1][j-1],Math.min(dp[i-1][j], dp[i][j-1]))+1;
        			max      = Math.max(dp[i][j],max);
        		}
        	}

        	//output
        	System.out.println(max);
        }
	}
}
