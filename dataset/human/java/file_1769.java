import java.util.*;

public class Main {
	//1706
	Scanner sc = new Scanner(System.in);
	int INF = 1 << 24;
	int [] cake;
	int k;
	
	class Edge{
		int from, to, cost;
		public Edge(int from, int to, int cost) {
			this.from = from;
			this.to = to;
			this.cost = cost;
		}
	}
	
	class State implements Comparable<State>{
		int now;
		int cost, visited;
		public State(int now, int cost, int visited) {
			this.now = now;
			this.cost = cost;
			this.visited = visited;
		}
		@Override
		public int compareTo(State o) {
			return this.cost - o.cost;
		}
	}

	private void doit() {
		while (true) {
			int m = sc.nextInt();
			int n = sc.nextInt();
			k = sc.nextInt();
			int d = sc.nextInt();
			if((m|n|k|d) == 0) break;
			cake = new int[m];
			for(int i = 0; i < m; i++){
				cake[i] = sc.nextInt();
			}
			ArrayList<Edge> list = new ArrayList<Edge>();
			for(int i = 0; i < d; i++){
				String a = sc.next();
				String b = sc.next();
				int cost = sc.nextInt();
				int from = changeInd(a);
				int to = changeInd(b);
				list.add(new Edge(from, to, cost));
				list.add(new Edge(to, from, cost));
			}
			int [][] res = bellman(list, Math.max(1, Math.max(m, n)) * 10 + 1, m, 2);
			int ans = INF;
			for(int i = 0; i < res[3].length; i++){
				ans = Math.min(ans, res[3][i]);
			}
			System.out.println(ans);
		}
	}
	
	private int changeInd(String a) {
		if(a.equals("H")){
			return 2;
		}
		if(a.equals("D")){
			return 3;
		}
		char c = a.charAt(0);
		String sub = a.substring(1);
		int num = Integer.parseInt(sub) -1;
		if(c == 'C'){
			return num * 10 + 1;
		}
		else{
			return num * 10;
		}
	}

	private int [][] bellman(ArrayList<Edge> data, int arraysize, int bitsize, int s){
		int m = data.size();
		int [][] d = new int[arraysize][1 << bitsize];
		for(int i = 0; i < arraysize; i++){
			Arrays.fill(d[i], INF);
		}
		d[s][0] = 0;
		while(true){
			boolean update = false;
			for(int i = 0; i < m; i++){
				Edge e = data.get(i);
				for(int j = 0; j < (1 << bitsize); j++){
					if(d[e.from][j] == INF) continue;
					if(e.from % 10 == 1){
						int ind = e.from / 10;
						if((j & (1 << ind)) > 0) continue;
						int nextind = j | 1 << ind;
						int nextcost = d[e.from][j] + e.cost * k - cake[ind];
						if(d[e.to][nextind] > nextcost){
							d[e.to][nextind] = nextcost;
							update = true;
						}
					}
					else{
						int nextcost = d[e.from][j] + e.cost * k;
						if(d[e.to][j] > nextcost){
							d[e.to][j] = nextcost;
							update = true;
						}
					}
				}
				
			}
			if(! update){
				break;
			}
		}
		return d;
	}

	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}
}
