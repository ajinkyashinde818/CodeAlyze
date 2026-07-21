import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(System.in);
		
		final int n = sc.nextInt();
		
		int[] parent = new int[n];
		Arrays.fill(parent, -1);
		
		int[] depth = new int[n];
		Arrays.fill(depth, Integer.MAX_VALUE);
		
		int[] degree = new int[n];
		int[] sibling = new int[n];
		Arrays.fill(sibling, -1);
		
		int[] height = new int[n];
		Arrays.fill(height, Integer.MIN_VALUE);
		
		ArrayList<LinkedList<Integer>> leafs = new ArrayList<LinkedList<Integer>>();
		for(int i = 0; i < n; i++){
			leafs.add(new LinkedList<Integer>());
		}
		
		LinkedList<Integer> p_queue = new LinkedList<Integer>();
		LinkedList<Integer> d_queue = new LinkedList<Integer>();
		
		for(int i = 0; i < n; i++){
			final int id = sc.nextInt();
			final int left = sc.nextInt();
			final int right = sc.nextInt();
			
			
			if(left  != -1){ leafs.get(id).add(left); }
			if(right != -1){ leafs.get(id).add(right); }
			
			if(left  != -1){ degree[id]++; }
			if(right != -1){ degree[id]++; }
			
			if(left  != -1){ sibling[left]  = right; }
			if(right != -1){ sibling[right] = left;  }
			
			if(left  != -1){ parent[left]  = id; }
			if(right != -1){ parent[right] = id; }
		}
		
		for(int i = 0; i < n; i++){
			if(parent[i] == -1){
				p_queue.add(i);
				d_queue.add(0);
			}
		}
		
		while(!p_queue.isEmpty()){
			final int node = p_queue.poll();
			final int dep = d_queue.poll();
			
			if(depth[node] <= dep){
				continue;
			}else{
				depth[node] = dep;
			}
			
			for(int next : leafs.get(node)){
				if(depth[next] <= dep + 1){
					continue;
				}
				
				p_queue.add(next);
				d_queue.add(dep + 1);
			}
		}
		
		for(int i = 0; i < n; i++){
			if(leafs.get(i).isEmpty()){
				p_queue.add(i);
				d_queue.add(0);
			}
		}
		
		while(!p_queue.isEmpty()){
			final int node = p_queue.poll();
			final int high = d_queue.poll();
			
			if(height[node] >= high){
				continue;
			}else{
				height[node] = high;
			}
			
			if(parent[node] != -1){
				p_queue.add(parent[node]);
				d_queue.add(high + 1);
			}
		}
		
		for(int i = 0; i < n; i++){
			System.out.printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", i, parent[i], sibling[i], degree[i], depth[i], height[i], parent[i] == - 1 ? "root" : leafs.get(i).isEmpty() ? "leaf" : "internal node");
		}
		
	}

	public static class Scanner {
		private BufferedReader br;
		private StringTokenizer tok;

		public Scanner(InputStream is) throws IOException {
			br = new BufferedReader(new InputStreamReader(is));
		}

		private void getLine() throws IOException {
			while (!hasNext()) {
				tok = new StringTokenizer(br.readLine());
			}
		}

		private boolean hasNext() {
			return tok != null && tok.hasMoreTokens();
		}

		public String next() throws IOException {
			getLine();
			return tok.nextToken();
		}

		public int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		public long nextLong() throws IOException {
			return Long.parseLong(next());
		}

		public void close() throws IOException {
			br.close();
		}
	}

}
