import java.util.Scanner;
public class Main{
	public static void main(String[] args){
        new Main().run();
    }
	char[][] map;
	int[][] sq;
	int max;
	int n;
	public void run(){
		Scanner scan = new Scanner(System.in);
		while(scan.hasNext()){
			int n = scan.nextInt();
			if(n == 0){
				break;
			}
			map = new char[n][];
			sq = new int[n][n];
			max = 0;
			for(int i = 0;i < n;i++){
				map[i] = scan.next().toCharArray();
			}
			for(int i = 0;i < n;i++){
				sq[0][i] = (map[0][i] == '.')?1:0;
				sq[i][0] = (map[i][0] == '.')?1:0;
			}
			for(int i = 1;i < n;i++){
				for(int j = 1;j < n;j++){
					if(map[i][j] == '*'){
						sq[i][j] = 0;
					}else if(sq[i-1][j-1] == 0 || sq[i-1][j] == 0 || sq[i][j-1] == 0){
						sq[i][j] = 1;
						max = Math.max(max,sq[i][j]);
					}else{
						sq[i][j] = Math.min(sq[i-1][j-1],Math.min(sq[i-1][j],sq[i][j-1]))+1;
						max = Math.max(max,sq[i][j]);
					}
				}
			}
			System.out.println(max);
		}
	}
}
