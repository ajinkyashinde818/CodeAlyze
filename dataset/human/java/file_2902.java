import java.util.Scanner;

public class Main{
	int[][] pat = {
		{4, 1, 4, 1, 2, 1, 2, 1},
		{1, 4, 1, 2, 1, 2, 1, 4},
		{4, 1, 2, 1, 2, 1, 4, 1},
		{1, 2, 1, 2, 1, 4, 1, 4},
		{2, 1, 2, 1, 4, 1, 4, 1},
		{1, 2, 1, 4, 1, 4, 1, 2},
		{2, 1, 4, 1, 4, 1, 2, 1},
		{1, 4, 1, 4, 1, 2, 1, 2},
	};
	
	Main(){
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNext()){
			String[] str = (sc.nextLine()).split(" ");
			int[] c = new int[8];
			for(int i = 0; i < 8; i++){
				c[i] = Integer.parseInt(str[i]);
			}
			
			int s = 99999, t = 0, p=0, q;
			for(int i = 0; i < 8; i++){
				int u = 0, v;
				String st = "";
				for(int j = 0; j < 8; j++){
					v = c[j] - pat[i][j];
					if(v < 0){
						v = 0;
					}
					u += v;
					st += Integer.toString(pat[i][j]);
				}
				q = Integer.parseInt(st);
				if(s > u || (s == u && p > q)){
					s = u;
					t = i;
					p = q;
				}
			}
			
			System.out.print(Integer.toString(pat[t][0]));
			for(int i = 1; i < 8; i++){
				System.out.print(" "+Integer.toString(pat[t][i]));
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args){
		new Main();
	}
}
