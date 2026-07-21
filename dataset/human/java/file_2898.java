import java.util.*;

public class Main {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			int[][] map  = new int[8][8];
			int[] p = new int[8];
			int[] a = new int[8];
			int[] b = new int[8];
			
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					if((i<4 && j%2==0) || (i>3 && j%2==1)){
						map[i][j] = 1;
					}else{
						map[i][j] = 2;
					}
				}
			}
			
			map[0][5] = 4; map[4][4] = 4;
			map[0][7] = 4; map[4][6] = 4;
			map[1][3] = 4; map[5][2] = 4;
			map[1][5] = 4; map[5][4] = 4;
			map[2][1] = 4; map[6][0] = 4;
			map[2][7] = 4; map[6][6] = 4;
			map[3][1] = 4; map[7][0] = 4;
			map[3][3] = 4; map[7][2] = 4;
			
	
			for(int i=0;i<8;i++){
				p[i] = sc.nextInt();
			}
			
			int sub = 0;
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					sub = map[i][j] - p[j];
					if(sub<0)a[i]-=sub;
				}
			}
			
			b = Arrays.copyOf(a, 8);
			Arrays.sort(a);
			
			for(int i=0;i<8;i++){
				if(b[i]==a[0]){
					for(int j=0;j<8;j++){
						if(j!=0)System.out.print(" ");
						System.out.print(map[i][j]);
					}
					break;
				}
			}
			System.out.println();
			
		}
	}	
}
