import java.util.*;
import java.io.*;
public class Main {
	public static void main(String args[]) {
		FastScanner in=new FastScanner();
		int n=in.nextInt();
		HashMap<Integer, Integer> hmap1=new HashMap<>();
		HashMap<Integer, Integer> hmap2=new HashMap<>();
		boolean chk=false;
		int ctr=0;
		for(int i=0;i<n;i++) {
			int x=in.nextInt();
			int y=in.nextInt();
			if(x==y) {
				ctr++;
			}
			else {
				ctr=0;
			}
			
			if(ctr==3 && !chk) {
				System.out.println("Yes");
				chk=true;
			}
		}
		if(!chk)
		System.out.println("No");
	}

	///////////////////////////
	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {
			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] nextArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
			return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}
}
