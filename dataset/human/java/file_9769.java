import java.util.*;
import java.io.*;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		HashMap hs = new HashMap();
		PrintWriter ou = new PrintWriter(System.out);
		int n = Integer.parseInt(sc.next());
		int m = Integer.parseInt(sc.next());
		int x = Integer.parseInt(sc.next());
		int[] c = new int[n];
		int[][] a = new int[n][m];
		for(int i = 0 ; i < n ; i++){
			c[i] = Integer.parseInt(sc.next());
			for(int j = 0 ; j < m ; j++){
				a[i][j] = Integer.parseInt(sc.next());
			}
		}
		sc.close();
		int yono = (int)Math.pow(10 , 9);
		int[] mo = new int[m];
		for(int i = 0 ; i < 1 << n ; i++){
			Arrays.fill(mo , 0);
			int y = 0;
			for(int j = 0 ; j < n ; j++){
				if((1 & i >> j) == 1){
					for(int k = 0 ; k < m ; k++){
						mo[k] += a[j][k];
					}
					y += c[j];
				}
			}
			boolean ebishu = true;
			for(int ii = 0 ; ii < m && ebishu ; ii++){
				if(mo[ii] < x) ebishu = false;
			}
			if(ebishu) yono = Math.min(yono , y);
		}
		if(yono == (int)Math.pow(10 , 9)) ou.print(-1);
		else ou.print(yono);
		ou.print("\n");
		ou.flush();
	}
}
