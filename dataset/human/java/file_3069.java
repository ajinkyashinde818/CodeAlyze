import java.util.*;

public class Main {

	public static void main(String[] args) {
		Main main = new Main();
		main.run();
	}

	ArrayList<ArrayList<Integer>> g = new ArrayList<>();
	int dist[];
	boolean used[];
	int INF = 1001001001;
	public void run() {
		Scanner sc = new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		for(int i=0; i<n; i++) {
			g.add(new ArrayList<>());
		}
		dist = new int[n];
		for(int i=0; i<n; i++) {
			dist[i]=INF;
		}
		used = new boolean[n];
		for(int i=0; i<m; i++) {
			int a=sc.nextInt();
			int b=sc.nextInt();
			a--;
			b--;
			g.get(a).add(b);
			g.get(b).add(a);
		}
		bfs(0,0);
		if(dist[n-1]<=2) {
			System.out.println("POSSIBLE");
		}else {
			System.out.println("IMPOSSIBLE");
		}
		sc.close();
	}


	public void bfs(int p, int d) {
		ArrayDeque<Integer> q = new ArrayDeque<>();
		q.add(p);
		dist[p]=0;
		used[p]=true;
		while(!q.isEmpty()) {
			int s = q.poll();
			for(int i=0; i<g.get(s).size(); i++) {
				int t = g.get(s).get(i);
				if(used[t]) continue;
				used[t]=true;
				dist[t]=dist[s]+1;
				q.add(t);
			}
		}
	}


}
