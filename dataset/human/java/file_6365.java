import java.io.*;
class Main {
	static StreamTokenizer st = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
	static int nextInt() throws IOException {
		st.nextToken();
		return (int)st.nval;
	}
	public static void main(String[] args) throws IOException {
		PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
		int k = nextInt(), s = nextInt(), ans = 0;
		for(int x=0;x<=k && x<=s;++x) {
			for(int y=0;y<=k && y+x<=s;++y) {
				if(s-x-y<=k) ++ans;
			}
		}
		pw.print(ans);
		pw.print('\n');
		pw.flush();
	}
}
