import java.io.*;
import java.util.*;

public class Main {

	static int n;
	static long INF = (long) 1e18 + 1;

	static class Edge implements Comparable<Edge> {
		int node;
		double cost;

		Edge(int u, double c) {
			node = u;
			cost = c;
		}

		@Override
		public int compareTo(Edge other) {
			if (cost != other.cost)
				return Double.compare(cost, other.cost);
			return node - other.node;
		}
	}

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner();
		PrintWriter out = new PrintWriter(System.out);
		int[] start = sc.nxtArr(2), end = sc.nxtArr(2);
		int n = sc.nextInt();
		int[][][] circles = new int[n][2][];
		for (int i = 0; i < n; i++) {
			circles[i][0] = sc.nxtArr(2);
			circles[i][1] = sc.nxtArr(1);
		}
		double[] dist = new double[n];
		Arrays.fill(dist, INF);
		PriorityQueue<Edge> pq = new PriorityQueue();
		for (int i = 0; i < n; i++)
			pq.add(new Edge(i, dist[i] = Math.max(0, dist(start, circles[i][0]) - circles[i][1][0])));
		while (!pq.isEmpty()) {
			Edge curr = pq.poll();
			int u = curr.node;
			double d = curr.cost;
			if (d - 1e-6 > dist[u])
				continue;
			for (int v = 0; v < n; v++) {
				double total = d
						+ Math.max(0, dist(circles[u][0], circles[v][0]) - circles[u][1][0] - circles[v][1][0]);
				if (total < dist[v])
					pq.add(new Edge(v, dist[v] = total));
			}

		}
		double ans = dist(start, end);
		for (int i = 0; i < n; i++)
			ans = Math.min(ans, dist[i] + Math.max(0, dist(end, circles[i][0]) - circles[i][1][0]));
		System.out.printf("%.9f\n", ans);
		out.close();

	}

	static double dist(int[] p1, int[] p2) {
		long dx = p1[0] - p2[0], dy = p1[1] - p2[1];
		return Math.sqrt(dx * dx + dy * dy);
	}

	static class Scanner {
		BufferedReader br;
		StringTokenizer st;

		Scanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		Scanner(String fileName) throws FileNotFoundException {
			br = new BufferedReader(new FileReader(fileName));
		}

		String next() throws IOException {
			while (st == null || !st.hasMoreTokens())
				st = new StringTokenizer(br.readLine());
			return st.nextToken();
		}

		String nextLine() throws IOException {
			return br.readLine();
		}

		int nextInt() throws IOException {
			return Integer.parseInt(next());
		}

		long nextLong() throws NumberFormatException, IOException {
			return Long.parseLong(next());
		}

		double nextDouble() throws NumberFormatException, IOException {
			return Double.parseDouble(next());
		}

		boolean ready() throws IOException {
			return br.ready();
		}

		int[] nxtArr(int n) throws IOException {
			int[] ans = new int[n];
			for (int i = 0; i < n; i++)
				ans[i] = nextInt();
			return ans;
		}

	}

	static void sort(int[] a) {
		shuffle(a);
		Arrays.sort(a);
	}

	static void shuffle(int[] a) {
		int n = a.length;
		Random rand = new Random();
		for (int i = 0; i < n; i++) {
			int tmpIdx = rand.nextInt(n);
			int tmp = a[i];
			a[i] = a[tmpIdx];
			a[tmpIdx] = tmp;
		}
	}

}
