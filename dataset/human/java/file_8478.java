import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	static boolean[] visited;
	static int[] ans;
	static ArrayList<Integer> tempRail, tempRoad;
	static ArrayList<Integer>[] road, rail;
	static int [] colorRoad, colorRail;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int l = sc.nextInt();
		
		//idea: construct a union-find with all the roads only
		//then, for each node, run dfs on it, and add nodes to the 
		//set if and only if they're in the same road-component 
		//and theres an edge between them
		//able to count all the members in the set exactly once and 
		//at the same time; if a and b are in the same set, then 
		//their count is equal; othewrise, it might be different
		road = new ArrayList[n];
		for(int i=0;i<n;i++) {
			road[i] = new ArrayList<>();
		}
		for(int i=0;i<k;i++) {
			int p = sc.nextInt()-1;
			int q = sc.nextInt()-1;
			road[p].add(q);
			road[q].add(p);
		}
		rail = new ArrayList[n];
		for(int i=0;i<n;i++) {
			rail[i] = new ArrayList<>();
		}
		for(int i=0;i<l;i++) {
			int r = sc.nextInt()-1;
			int s = sc.nextInt()-1;
			rail[r].add(s);
			rail[s].add(r);
		}
		visitedRail = new boolean[n];
		visitedRoad = new boolean[n];
		colorRail = new int[n];
		colorRoad = new int[n];
		int c1 = 0;
		int c2 =0;
		for(int i=0;i<n;i++) {
			if(!visitedRail[i]) {
				tempRail = new ArrayList<>();
				dfsRail(i);
				for(int x : tempRail) {
					colorRail[x] = c1;
				}
				c1++;
			}
			if(!visitedRoad[i]) {
				tempRoad = new ArrayList<>();
				dfsRoad(i);
				for(int x : tempRoad) {
					colorRoad[x] = c2;
				}
				c2++;
			}
		}
		HashMap<Node, Integer> freq=  new HashMap<>();
		for(int i=0;i<n;i++) {
			freq.put(new Node(colorRail[i],colorRoad[i]), freq.getOrDefault(new Node(colorRail[i],colorRoad[i]),0)+1);
		}
		int ans[] = new int[n];
		for(int i=0;i<n;i++) {
			ans[i] = freq.get(new Node(colorRail[i],colorRoad[i]));
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i=0;i<n;i++) {
			sb.append(ans[i]);
			sb.append("\n");
		}
		System.out.println(sb.toString());
	}
	static boolean [] visitedRail, visitedRoad;
	static void dfsRail(int i) {
		visitedRail[i] = true;
		tempRail.add(i);
		for(int j : rail[i]) {
			if(!visitedRail[j]) {
				dfsRail(j);
			}
		}
	}
	static void dfsRoad(int i) {
		visitedRoad[i] = true;
		tempRoad.add(i);
		for(int j : road[i]) {
			if(!visitedRoad[j]) {
				dfsRoad(j);
			}
		}
	}
	static class Node{
		int a;
		int b;
		public Node(int a,int b) {
			this.a = a;
			this.b = b;
		}
		@Override
		public int hashCode() {
			return a*129621+b*3692893;
		}
		@Override
		public boolean equals(Object o) {
			Node x = (Node)o;
			return x.a==a && x.b==b;
		}
	}
	
}
