import java.util.*;


public class Main {

	Scanner sc = new Scanner(System.in);
	public static void main(String[] args) {
		new Main().doit();

	}
	
	private void doit(){
		new C();
	}
	
	class C{
		
		ArrayList<ArrayList<Integer>> data;
		int n, c;
		
		int [] vx = {0,0,1,-1,1,-1};
		int [] vy = {-1,1,0,0,1,-1};
		boolean [][] visited;
		
		C(){
			while(true){
				n = sc.nextInt();
				c = sc.nextInt();
				if((n|c) == 0) break;
				data = new ArrayList<ArrayList<Integer>>();
				for(int i = 0 ; i < n; i++){
					data.add(new ArrayList<Integer>());
				}
				
				for(int i = 0 ; i < n; i++){
					for(int j = 0; j <= i; j++){
						data.get(i).add(sc.nextInt());
					}
				}
				visited = new boolean[n][n];
				int max = -1 *  1 << 24;;
				for(int i = 0 ; i < n; i++){
					for(int j = 0 ; j < data.get(i).size(); j++){
						int num = data.get(i).get(j);
						if(num == 0){
							int sum = 0;
							data.get(i).set(j, c);
							//disp();
							reset();
							sum -= dfs(j, i, c);
							//System.out.println("sum1 = " + sum);
							for(int k = 0 ; k < vx.length; k++){
								int xx = j + vx[k];
								int yy = i + vy[k];
								if(! isOK(xx,yy)){
									continue;
								}
								if(visited[yy][xx]) continue;
								if(data.get(yy).get(xx) == c || data.get(yy).get(xx) == 0) continue;
								int res  = dfs(xx,yy, data.get(yy).get(xx));
								//disp();
								//System.out.println(res + " i  " + yy + " xx " + xx);
								sum += res;
							}
							//System.out.println("sum = " +sum + " i " + i + " j " + j );
							max = Math.max(max, sum);
							data.get(i).set(j, 0);
						}
					}
				}
				System.out.println(max);
			}
		}

		private void disp() {
			for(int i = 0 ; i < n; i++){
				for(int j = 0 ; j < data.get(i).size(); j++){
					System.out.print(data.get(i).get(j));
				}
				System.out.println();
			}
			System.out.println();
			for(int i = 0 ; i < n; i++){
				for(int j = 0; j < data.get(i).size(); j++){
					System.out.print(visited[i][j]);
				}
				System.out.println();
			}
			System.out.println();
			
		}

		private void reset() {
			for(int i = 0 ; i < n; i++){
				Arrays.fill(visited[i], false);
			}
			
		}

		private int dfs(int x, int y, int color) {
			//System.out.println("x " + x  + " y = " + y);
			boolean findzero = false;
			int sum = 0;
			visited[y][x] = true;
			for(int i = 0 ; i < vx.length; i++){
				int xx = x + vx[i];
				int yy = y + vy[i];
				if(! isOK(xx, yy)) continue;
				if(xx == 3 && yy == 3){
					
					//System.out.println("xx" + xx + " yy " + yy + " color1 " + color  + visited[yy][xx]);
				}
				if(visited[yy][xx]) continue;
				if(data.get(yy).get(xx) == 0){
					findzero = true;
					//break;
				}
				else if(data.get(yy).get(xx) == color){
					//System.out.println("xx" + xx + " yy " + yy + " color " + color );
					int res = dfs(xx, yy, color);
					if(res == 0){
						findzero = true;
						//break;
					}
					sum += res;
				}
			}
			if(findzero) return 0;
			return sum + 1;
		}

		private boolean isOK(int xx, int yy) {
			if(0<= yy && yy < n && 0 <= xx && xx < data.get(yy).size()){
				return true;
			}
			return false;
		}
	}
	
	class A{
		A(){
			while(true){
				int w = sc.nextInt();
				int d = sc.nextInt();
				if((w|d) == 0)break;
				int [] data =new int[w];
				int [] data2 = new int[d];
				int sum = 0;
				for(int i = 0 ; i < w; i++){
					data[i] = sc.nextInt();
					sum += data[i];
				}
				for(int i = 0 ; i < d; i++){
					data2[i] = sc.nextInt();
					sum += data2[i];
				}
				//System.out.println(" sum = " +sum);
				
				boolean [] used = new boolean[w];
				boolean [] used2 = new boolean[d];
				for(int i = 0 ; i < w; i++){
					for(int j = 0 ; j < d; j++){
						if(! used2[j]){
							if(data[i] == data2[j]){
								sum -= data2[j];
								used2[j] = true;
								break;
							}
						}
					}
					//System.out.println("i = " + i+ "sum = " + sum);
				}
				System.out.println(sum);
			}
		}
	}

}
