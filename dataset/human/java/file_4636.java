import java.awt.geom.*;
import java.io.*;
import java.util.*;
public class Main {
	//1453 start
	//1509 cording end
	//1517 sample match
	
	int [] vx = {0,1,0,-1,1,-1 };
	int [] vy = {1,0,-1,0,1,-1};
	int n, m;
	ArrayList<ArrayList<Integer>> data ;
	boolean [][] used;
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(true){
			n = sc.nextInt();
			m = sc.nextInt();
			if((m|n) == 0) break;
			data = new ArrayList<ArrayList<Integer>>();
			for(int i = 0 ; i < n; i++){
				data.add(new ArrayList<Integer>());
				for(int j = 0; j <= i; j++){
					data.get(i).add(sc.nextInt());
				}
			}
			
			int max = -1 * 1 << 24;
			for(int i = 0; i < n; i++){
				for(int j = 0 ; j <= i; j++){
					if(data.get(i).get(j) != 0) continue;
					used = new boolean[n][n];
					data.get(i).set(j, m);
					int sum = -1 * dfs(j,i,m);
					for(int k = 0 ; k < vx.length; k++){
						int xx = j + vx[k];
						int yy = i + vy[k];
						if(! isOK(xx, yy)) continue;
						if(used[yy][xx] ) continue;
						if(data.get(yy).get(xx) == m || data.get(yy).get(xx) == 0) continue;
						sum += dfs(xx,yy, data.get(yy).get(xx));
					}
					max = Math.max(max, sum);
					data.get(i).set(j, 0);
				}
			}
			System.out.println(max);
		}
	}
	private int dfs(int x, int y, int  color) {
		used[y][x] = true;
		int res = 0;
		boolean flg = false;
		for(int i = 0 ; i < vx.length; i++){
			int xx =x + vx[i];
			int yy = y + vy[i];
			if(! isOK(xx, yy)) continue;
			if(used[yy][xx]) continue;
			if(data.get(yy).get(xx) == 0){
				flg = true;
			}
			else if(data.get(yy).get(xx) == color){
				int temp = dfs(xx,yy, color);
				if(temp == 0) flg = true;
				res += temp;
			}
		}
		if(flg) return 0;
		return res + 1;
	}
	private boolean isOK(int xx, int yy) {
		if(0 <= yy && yy < n && 0<= xx && xx < data.get(yy).size()){
			return true;
		}
		return false;
	}
	public static void main(String [] args){
		new Main().doit();
	}
}
