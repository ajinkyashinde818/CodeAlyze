import java.util.*;

public class Main{
	int INF = 1 << 24;
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			int n = sc.nextInt();
			sc.nextLine();
			int [][] pass = new int[n + 1][n + 1];
			for(int i = 0; i <= n; i++){
				Arrays.fill(pass[i], INF);
				pass[i][i] = 0;
			}
			HashMap<String, Integer> label = new HashMap<String, Integer>();
			ArrayList<String> gotostr = new ArrayList<String>();
			ArrayList<Integer> gotoind = new ArrayList<Integer>();
			for(int i = 0; i < n; i++){
				String s = sc.nextLine();
				if(s.contains(":")){
					String key = s.split(":")[0];
					label.put(key, i);
					pass[i][i+1] = 0;
				}
				else{
					//goto
					String key = s.split("[ ;]")[1];
					gotostr.add(key);
					gotoind.add(i);
					pass[i][i+1] = 1;
				}
			}
			
			for(int i = 0; i < gotoind.size(); i++){
				int ind = gotoind.get(i);
				String key = gotostr.get(i);
				int to = label.get(key);
				pass[ind][to] = 0;
			}
			
			n = pass.length;
			for(int j = 0; j < n; j++){
				for(int i = 0; i < n; i++){
					for(int k = 0; k < n; k++){
						pass[i][k] = Math.min(pass[i][k], pass[i][j] + pass[j][k]);
					}
				}
			}
			System.out.println(pass[0][n-1]);
		}
	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}
}
