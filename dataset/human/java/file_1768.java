import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) throws IOException {
		new Main().run();
	}

	@SuppressWarnings("unchecked")
	private void run() throws IOException {
		Scanner scanner = new Scanner(System.in);
		while (true) {
			m = scanner.nextInt();
			n = scanner.nextInt();
			k = scanner.nextInt();
			d = scanner.nextInt();
			if ((m | n | k | d) == 0)
				break;
			int[] cake = new int[m];
			for (int i = 0; i < m; i++) {
				cake[i] = scanner.nextInt();
			}
			int N = m + n + 2;
			List<Pair>[] lists = new ArrayList[N];
			for (int i = 0; i < N; i++) {
				lists[i] = new ArrayList<Pair>();
			}
			while (d-- > 0) {
				int s = get(scanner.next());
				int t = get(scanner.next());
				int cost = scanner.nextInt() * k;
				lists[s].add(new Pair(t, cost));
				lists[t].add(new Pair(s, cost));
			}
			int[][] dist = new int[1 << m][N];
			for (int[] a : dist)
				Arrays.fill(a, 1 << 28);
			boolean[][] u = new boolean[1 << m][N];
			dist[0][n + m] = 0;
			u[0][n + m] = true;
			PriorityQueue<Pair> deque = new PriorityQueue<Pair>();
			deque.add(new Pair(n + m, 0, 0));
			while (!deque.isEmpty()) {
				Pair pair = deque.poll();
				int s = pair.first;
				int cost = pair.second;
				int bit = pair.bit;
				if(dist[bit][s]<cost)
					continue;
				for (Pair p : lists[s]) {
					if (m <= p.first) {
						int v = cost + p.second;
						if (v < dist[bit][p.first]) {
							dist[bit][p.first] = v;
							deque.offer(new Pair(p.first, v, bit));
						}
					} else {
						int aa = (bit >> p.first) & 1;
						if (aa == 1 )
							continue;
						int v = cost + p.second - cake[p.first];
						int newbit = bit | 1 << p.first;
						if (dist[newbit][p.first] > v) {
							dist[newbit][p.first] = v;
							deque.offer(new Pair(p.first, v, newbit));
						}
					}
				}
			}

			int min = 1 << 28;
			for (int j = 0; j < 1 << m; j++) {
				min = Math.min(min, dist[j][n + m + 1]);
			}
			System.out.println(min);
		}
	}

	private int get(String s) {
		if (s.charAt(0) == 'H')
			return n + m;
		if (s.charAt(0) == 'D')
			return n + m + 1;
		int x = Integer.parseInt(s.substring(1)) - 1;
		return s.charAt(0) == 'C' ? x : x + m;
	}

	int m, n, k, d;

	class Pair implements Comparable<Pair>{
		int first;
		int second;
		int bit;

		public Pair(int first, int second) {
			super();
			this.first = first;
			this.second = second;
		}

		public Pair(int first, int second, int bit) {
			super();
			this.first = first;
			this.second = second;
			this.bit = bit;
		}

		@Override
		public String toString() {
			return "Pair [first=" + first + ", second=" + second + ", bit="
					+ bit + "]";
		}

		@Override
		public int compareTo(Pair o) {
			return this.second-o.second;
		}

	}
}
