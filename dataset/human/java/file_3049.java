import java.util.Arrays;
import java.util.Comparator;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.PriorityQueue;
import java.util.Scanner;

class Pair<F, S>{
	public final F first;
	public final S second;

	public Pair (F first, S second) {
		this.first = first;
		this.second = second;
	}

}
class Graph{
	final int INF = Integer.MAX_VALUE/2;
	private int V,E;
	LinkedList<Pair<Integer, Integer>>[] edges;
	@SuppressWarnings("unchecked")
	public Graph(int v,int e){
		this.V = v; this.E = e;
		edges = new LinkedList[V];
	}

	public int[] dijkstra(int s){
		int[] d = new int[V];
		boolean[] used = new boolean[V];
		Arrays.fill(used,false);
		Arrays.fill(d,INF);
		d[s]=0;

		PriorityQueue<Pair<Integer, Integer>> que=new PriorityQueue<Pair<Integer, Integer>>(new Comparator<Pair<Integer, Integer>>() {
			public int compare(Pair<Integer, Integer> o1, Pair<Integer, Integer> o2) {
				return o1.second - o2.second;
			}
		});

		que.add(new Pair<Integer, Integer>(s, 0));
		while(!que.isEmpty()){
			Pair<Integer, Integer> now = que.poll();
			int point = now.first;
			if(used[point]) continue;
			used[point]=true;
			for(Iterator<Pair<Integer, Integer>> it = edges[point].iterator(); it.hasNext();) {
				Pair<Integer, Integer> next = it.next();
				if(!used[next.first] && d[next.first] > d[point] + next.second) {
					d[next.first] = d[point] + next.second;
					que.add(new Pair<Integer, Integer>(next.first, d[next.first]));
				}
			}
		}
		return d;
	}
}
class Main{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		while(sc.hasNext()){
			int N = sc.nextInt(), M = sc.nextInt();
			Graph g = new Graph(N, M);
			for(int i = 0; i < N; i++) {
				g.edges[i] = new LinkedList<Pair<Integer, Integer>>();
			}
			for(int i = 0; i < M; i++) {
				int s = sc.nextInt();
				int t = sc.nextInt();
				g.edges[s - 1].add(new Pair<Integer, Integer>(t - 1, 1));
				g.edges[t - 1].add(new Pair<Integer, Integer>(s - 1, 1));
			}
			int[] ans = g.dijkstra(0);
			if(ans[N - 1] <= 2) {
				System.out.println("POSSIBLE");
			}
			else {
				System.out.println("IMPOSSIBLE");
			}
		}
	}
}
