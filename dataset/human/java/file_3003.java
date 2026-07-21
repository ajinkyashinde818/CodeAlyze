import java.util.*;
import static java.lang.Math.*;

public class Main {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		
		// 入力
		int n = sc.nextInt();
		Graph g = new Graph(n, false);
		int m = sc.nextInt();
		for(int i = 0; i < m; i++){
		    int from = sc.nextInt()-1;
		    int to = sc.nextInt()-1;
		    g.add(from, to);
		}
		
		// 計算
		String result = "IMPOSSIBLE";
		long[] dist = g.bfs(0);
		if(dist[n-1] == 2) result = "POSSIBLE";
		
		// 出力
		System.out.println(result);
	}
}

class Graph {
	int n;
	boolean directed;
	ArrayList<Edge>[] adjList;
	int m;
	long[] dist;
	long[][] distWF;
	int start;
	int[] prev;
	ArrayList<Integer> path;
	long INF = 1001001001001001001L;

	public Graph (int n, boolean directed) {
		this.n = n;
		this.m = 0;
		this.directed = directed;
		this.adjList = new ArrayList[n];
		for(int i = 0; i < n; i++){
			adjList[i] = new ArrayList<Edge>();
		}
	}
	
	public void add(int from, int to) {
		add(from, to, 1);
	}
	public void add(int from, int to, int w) {
		adjList[from].add(new Edge(from, to, w));
		this.m++;
		if(!directed){
			adjList[to].add(new Edge(to, from, w));
			this.m++;
		}
	}
	
	public long[] bfs(int start) { // O(M)
		this.start = start;
		this.prev = new int[n];
		prev[start] = start;
		this.dist = new long[n];
		Arrays.fill(dist, INF);
		dist[start] = 0;
		ArrayDeque<Integer> q = new ArrayDeque<Integer>();
		q.add(start);
		while(!q.isEmpty()){
			int now = q.poll();
			for(Edge e : adjList[now]){
				if(dist[e.to] != INF) continue;
				dist[e.to] = dist[now] + e.w;
				prev[e.to] = now;
				q.add(e.to);
			}
		}
		return dist;
	}
	
	public long[] dijkstra(int start) { // O(MlogM)
		this.start = start;
		this.prev = new int[n];
		prev[start] = start;
		this.dist = new long[n];
		Arrays.fill(dist, INF);
		dist[start] = 0;
		PriorityQueue<Vertex> q = new PriorityQueue<Vertex>((x, y) -> Long.compare(x.distance, y.distance));
		q.add(new Vertex(start, 0));
		while(!q.isEmpty()){
			Vertex now = q.poll();
			if(now.distance > dist[now.id]) continue; 
			for(Edge e : adjList[now.id]){
				long newDist = now.distance + e.w;
				if(dist[e.to] <= newDist) continue;
				dist[e.to] = newDist;
				prev[e.to] = now.id;
				q.add(new Vertex(e.to, newDist));
			}
		}
		return dist;
	}
	
	public long[][] wf() { // O(N^3)
		this.distWF = new long[n][n];
		for(int i = 0; i < n; i++){
			Arrays.fill(distWF[i], INF);
			distWF[i][i] = 0;
		}
		for(ArrayList<Edge> list : adjList){
			for(Edge e : list){
				distWF[e.from][e.to] = e.w;
			}
		}
		for(int k = 0; k < n; k++){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					distWF[i][j] = min(distWF[i][j], distWF[i][k] + distWF[k][j]);
				}
			}
		}
		return distWF;
	}
	
	public boolean bf(int start) { // O(NM)
		this.start = start;
		this.prev = new int[n];
		prev[start] = start;
		this.dist = new long[n];
		Arrays.fill(dist, INF);
		dist[start] = 0;
		boolean hasNegativeLoop = false;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				for(Edge e : adjList[j]){
					if(dist[e.to] <= dist[e.from] + e.w) continue;
					dist[e.to] = dist[e.from] + e.w;
					prev[e.to] = e.from;
					if(i == n-1) hasNegativeLoop = true;
				}
			}
		}
		return hasNegativeLoop;
	}
	
	public ArrayList<Integer> pathTo(int to){
		if(this.path == null) this.path = new ArrayList<Integer>();
		if(to != start) pathTo(prev[to]);
		path.add(to);
		return path;
	}
	
	public String toString(){
		StringBuilder sb = new StringBuilder();
		for(ArrayList<Edge> list : adjList){
			for(Edge e : list){
				sb.append(e.toString());
				sb.append("\n");
			}
		}
		return sb.toString();
	}
	
	public String distToString(){
		if(dist != null) return Arrays.toString(dist);
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(distWF[i][j] == INF){
					sb.append("from:" + i + " to:" + j + " dist:INF" + "\n");
				}else{
					sb.append("from:" + i + " to:" + j + " dist:" + distWF[i][j] + "\n");
				}
			}
		}
		return sb.toString();
	}
	
	class Edge {
		int from;
		int to;
		int w;
		
		Edge(int from, int to, int w){
			this.from = from;
			this.to = to;
			this.w = w;
		}
		
		public String toString(){
			return "from:" + from + " to:" + to + " w:" + w;
		}
	}
	
	class Vertex {
		int id;
		long distance;
		
		Vertex(int id, long distance){
			this.id = id;
			this.distance = distance;
		}
		
		public String toString(){
			return "id:" + id + " distance:" + distance;
		}
	}
}
