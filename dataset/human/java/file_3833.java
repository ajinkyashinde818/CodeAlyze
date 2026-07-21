import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class Main {
	
	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens()) {
				String cad = br.readLine();
				if (cad == null)
					return null;
				tk=new StringTokenizer(cad);
			}
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public long nextLong() throws NumberFormatException, IOException{
			return Long.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}
	
	
	static char[] s;
	
	static int f() {
		int l = 0;
		int r = s.length - 1;
		int add = 0;
		while(l < r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			}
			else if (s[l] == 'x') {
				add++;
				l++;
			}
			else if (s[r] == 'x') {
				add++;
				r--;
			}
			else
				return -1;
		}
		return add;
	}
	
	public static void main(String args[]) throws IOException {
		Scanner sc = new Scanner();
		s = sc.next().toCharArray();
		System.out.println(f());
	}

}
