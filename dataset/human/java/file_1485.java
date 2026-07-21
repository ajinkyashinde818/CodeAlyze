import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	int N,M;
	char[][] a,b;

	public boolean check(){
		for(int i = 0;i < N;i++){

			for(int j = 0;j < N;j++){
				if(i + M - 1 >= N || j + M - 1>= N)continue;
				boolean flag = true;
				for(int x = 0;x < M;x++){

					for(int y = 0;y < M;y++){

						if(a[i+x][j+y] != b[x][y]){
							flag = false;
							x = y = M;
						}
					}
				}

				if(flag){
					return true;
				}
			}
		}
		return false;
	}

	public void solve() {
		N = nextInt();
		M = nextInt();

		a = new char[N][];
		b = new char[M][];

		for(int i = 0;i < N;i++){
			a[i] = next().toCharArray();
		}


		for(int i = 0;i < M;i++){
			b[i] = next().toCharArray();
		}


		if(check()){
			out.println("Yes");
		}else{
			out.println("No");
		}
	}

	public static void main(String[] args) {
		out.flush();
		new Main().solve();
		out.close();
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
}
