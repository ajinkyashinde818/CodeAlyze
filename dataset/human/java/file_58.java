import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;
import java.util.PriorityQueue;

public class Main implements Runnable{
	int N,M;
	int[] a,b;

	private class P implements Comparable<P>{
		int x,y;
		public P(int x,int y){
			this.x = x;
			this.y = y;
		}

		public int compareTo(P p){
			if(this.x == p.x){
				return this.y - p.y;
			}
			return this.x - p.x;
		}
	}

	public void solve() {
		N = nextInt();
		M = nextInt();

		a = new int[N + 1];
		b = new int[N + 1];

		for(int i = 1;i <= N;i++){
			a[i] = i;
		}
		int cnt = 0;
		for(int i = 0;i < M;i++){
			int e = nextInt();
			b[e] = --cnt;
		}

		PriorityQueue<P> pq = new PriorityQueue<P>();

		for(int i = 1;i <= N;i++){
			P p = new P(b[i],a[i]);
			pq.add(p);
		}

		while(pq.size() > 0){
			out.println(pq.poll().y);
		}
	}

	public static void main(String[] args) {
		new Thread(null,new Main(),"",32 * 1024 * 1024).start();
	}

	/* Input */
	private static final InputStream in = System.in;
	private static final PrintWriter out = new PrintWriter(System.out);
	private final byte[] buffer = new byte[2048];
	private int p = 0;
	private int buflen = 0;

	private boolean hasNextByte() {
		if (p < buflen)
			return true;
		p = 0;
		try {
			buflen = in.read(buffer);
		} catch (IOException e) {
			e.printStackTrace();
		}
		if (buflen <= 0)
			return false;
		return true;
	}

	public boolean hasNext() {
		while (hasNextByte() && !isPrint(buffer[p])) {
			p++;
		}
		return hasNextByte();
	}

	private boolean isPrint(int ch) {
		if (ch >= '!' && ch <= '~')
			return true;
		return false;
	}

	private int nextByte() {
		if (!hasNextByte())
			return -1;
		return buffer[p++];
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = -1;
		while (isPrint((b = nextByte()))) {
			sb.appendCodePoint(b);
		}
		return sb.toString();
	}

	public int nextInt() {
		return Integer.parseInt(next());
	}

	public long nextLong() {
		return Long.parseLong(next());
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}

	@Override
	public void run() {
		out.flush();
		new Main().solve();
		out.close();

	}
}
