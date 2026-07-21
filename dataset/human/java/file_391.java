import java.io.*;
import java.util.*;

public class Main {

	private static Scanner sc;
	private static Printer pr;

	private static void solve() {
		long xs = sc.nextInt();
		long ys = sc.nextInt();
		long xe = sc.nextInt();
		long ye = sc.nextInt();
		int n = sc.nextInt();

		long[] x = new long[n];
		long[] y = new long[n];
		long[] r = new long[n];
		for (int i = 0; i < n; i++) {
			x[i] = sc.nextInt();
			y[i] = sc.nextInt();
			r[i] = sc.nextInt();
		}

		Dijkstra di = new Dijkstra(n + 2);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				double d = Math.max(0, Math.sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) - r[i] - r[j]);
				di.addEdge(i, j, d);
				di.addEdge(j, i, d);
			}

			double ds = Math.max(0, Math.sqrt((x[i] - xs) * (x[i] - xs) + (y[i] - ys) * (y[i] - ys)) - r[i]);
			double de = Math.max(0, Math.sqrt((x[i] - xe) * (x[i] - xe) + (y[i] - ye) * (y[i] - ye)) - r[i]);
			di.addEdge(n, i, ds);
			di.addEdge(i, n + 1, de);
		}

		double ret = di.getShortestPath(n, n + 1);
		double dse = Math.sqrt((xe - xs) * (xe - xs) + (ye - ys) * (ye - ys));

		pr.printf("%.10f\n", Math.min(ret, dse));
	}

	private static class Dijkstra {
		private static final double INF = 1e20;
		double[] d;
		double[][] edges;
		PriorityQueue<Vertex> pq;
		int n;
		int s;

		Dijkstra(int n) {
			this.n = n;
			edges = new double[n][n];
			for (int ii = 0; ii < n; ii++) {
				Arrays.fill(edges[ii], INF);
			}
			s = - 1;
		}

		// i, j:0-indexed
		public void addEdge(int i, int j, double c) {
			edges[i][j] = c;
		}

		public double getShortestPath(int i, int j) {
			if (s != i) {
				d = new double[n];
				pq = new PriorityQueue<Vertex>();
				Arrays.fill(d, INF);
				d[i] = 0;
				pq.add(new Vertex(i, d[i]));

				while (!pq.isEmpty()) {
					Vertex u = pq.poll();
					if (d[u.me] < u.d) {
						continue;  // skip old vertex
					}

					for (int ii = 0; ii < n; ii++) {
						if (d[ii] > d[u.me] + edges[u.me][ii]) {
							d[ii] = d[u.me] + edges[u.me][ii];
							pq.add(new Vertex(ii, d[ii]));
						}
					}
				}

				s = i;
			}

			return d[j];
		}

		private static class Vertex implements Comparable<Vertex> {
			int me; // me
			double d; // cost

			Vertex(int u, double w) {
				this.me = u;
				this.d = w;
			}

			@Override
			public int compareTo(Vertex o) {
				return Double.compare(this.d, o.d);
			}
		}
	}

	// ---------------------------------------------------
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		pr = new Printer(System.out);

		solve();

		pr.close();
		sc.close();
	}

	@SuppressWarnings("unused")
	private static class Scanner {
		BufferedReader br;

		Scanner (InputStream in) {
			br = new BufferedReader(new InputStreamReader(in));
		}

		private boolean isPrintable(int ch) {
			return ch >= '!' && ch <= '~';
		}

		private boolean isCRLF(int ch) {
			return ch == '\n' || ch == '\r' || ch == -1;
		}

		private int nextPrintable() {
			try {
				int ch;
				while (!isPrintable(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}

				return ch;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		String next() {
			try {
				int ch = nextPrintable();
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (isPrintable(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		int nextInt() {
			try {
				// parseInt from Integer.parseInt()
				boolean negative = false;
				int res = 0;
				int limit = -Integer.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Integer.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				int multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		long nextLong() {
			try {
				// parseLong from Long.parseLong()
				boolean negative = false;
				long res = 0;
				long limit = -Long.MAX_VALUE;
				int radix = 10;

				int fc = nextPrintable();
				if (fc < '0') {
					if (fc == '-') {
						negative = true;
						limit = Long.MIN_VALUE;
					} else if (fc != '+') {
						throw new NumberFormatException();
					}
					fc = br.read();
				}
				long multmin = limit / radix;

				int ch = fc;
				do {
					int digit = ch - '0';
					if (digit < 0 || digit >= radix) {
						throw new NumberFormatException();
					}
					if (res < multmin) {
						throw new NumberFormatException();
					}
					res *= radix;
					if (res < limit + digit) {
						throw new NumberFormatException();
					}
					res -= digit;

				} while (isPrintable(ch = br.read()));

				return negative ? res : -res;
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		float nextFloat() {
			return Float.parseFloat(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			try {
				int ch;
				while (isCRLF(ch = br.read())) {
					if (ch == -1) {
						throw new NoSuchElementException();
					}
				}
				StringBuilder sb = new StringBuilder();
				do {
					sb.appendCodePoint(ch);
				} while (!isCRLF(ch = br.read()));

				return sb.toString();
			} catch (IOException e) {
				throw new NoSuchElementException();
			}
		}

		void close() {
			try {
				br.close();
			} catch (IOException e) {
				//				throw new NoSuchElementException();
			}
		}
	}

	private static class Printer extends PrintWriter {
		Printer(PrintStream out) {
			super(out);
		}
	}
}
