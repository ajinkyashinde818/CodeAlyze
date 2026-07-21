import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.NoSuchElementException;

public class Main {
	int N;
	String[] s;
	char[][] c;
	int[] depth;
	public void print(){
		for(int i = 0;i < N;i++){
			for(int j = 0;j < s[i].length();j++){
				out.print(c[i][j]);
			}
			out.println();
		}
	}
	public void solve() {
		while (true) {
			N = nextInt();
			if (N == 0)
				break;
			s = new String[N];
			c = new char[N][];
			depth = new int[N];
			for (int i = 0; i < N; i++) {
				s[i] = next();
				c[i] = s[i].toCharArray();
				int d = 0;
				while(c[i][d] == '.'){
					d++;
				}
				depth[i] = d;
			}

			for(int i = 1;i < N;i++){
				for(int j = 0;j < s[i].length() - 1;j++){
					if(c[i][j] == '.' && c[i][j + 1] >= 'a' && c[i][j + 1]  <= 'z'){
						c[i][j] = '+';
					}
				}
			}

			for (int j = 0; j <= 50000; j++) {
				for (int i = 1; i < N; i++) {
					if(j >= s[i].length())
						continue;
					if(c[i][j] == '+'){
						int ii = 1;
						boolean find = false;
						while(i + ii < N){
							if(depth[i + ii] < depth[i]){
								break;
							}
							if(c[i + ii][j] == '+'){
								find = true;
								break;
							}

							ii++;
						}

						if(find){
							for(int k = 1;k < ii;k++){
								c[i + k][j] ='|';
							}
						}
					}
				}
			}

			for(int i = 0;i < N;i++){
				for(int j = 0;j < s[i].length();j++){
					if(c[i][j] == '.'){
						c[i][j] = ' ';
					}
				}
			}
			print();
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
