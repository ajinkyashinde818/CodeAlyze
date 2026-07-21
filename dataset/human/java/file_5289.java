import java.util.*;

public class Main{
	public static int solve(char[][] map){
		int count = 1;
		int max = 0;
		for(int i = 1; i < map.length-max; i++){
			for(int j = 1; j < map.length-max; j++){
				if( map[i][j] == '.' ){
					int k = 1;
					for(int l = 0; l < count; l++){
						while( map[i+l][j+k+l] == '.' && map[i+k+l][j+l] == '.' ){
							k++;
						}
						if( l == 0 ){
							count = k+l;
						} else if( count > k+l ){
							count = k+l;
						}
						
						if( k == 0 ){
							break;
						}
						k = 0;
					}
					if( count > max ){
						max = count;						
					}
					count = 1;
				}
				
			}
		}
		return max;
	}
	
	public static void main(String[] args){
		Scanner stdIn = new Scanner(System.in);
		
		int n;
		while( (n = stdIn.nextInt()) != 0 ){
			String[] s = new String[n];
			stdIn.nextLine();
			for(int i = 0; i < n; i++){
				s[i] = stdIn.nextLine();
			}
			char[][] map = new char[n+2][n+2];
			for(int i = 1; i <= n; i++){
				for(int j = 1; j <= n; j++){
					map[i][j] = s[i-1].charAt(j-1);
				}
			}
			System.out.println(solve(map));
		}
	}
}
