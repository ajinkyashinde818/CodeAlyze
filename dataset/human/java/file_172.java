import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) {
		FastScanner br = new FastScanner();
		ArrayList<Integer> caca = new ArrayList<Integer>();
		int min = Integer.MAX_VALUE;
		for(int i = br.ni();i>0;i--) {
			int n = br.ni();
			if(Math.abs(n)<min)min=Math.abs(n);
			caca.add(n);
		}
		long total = 0;
		for(int i = 0;i<caca.size()-1;i++) {
			if(caca.get(i)<0) {
				caca.set(i, caca.get(i)*-1);
				caca.set(i+1, caca.get(i+1)*-1);
			}
			total+=caca.get(i);
		}
		if(caca.get(caca.size()-1)>=0) {
			total+=caca.get(caca.size()-1);
			System.out.println(total);
			System.exit(0);
		}
		if(min==Math.abs(caca.get(caca.size()-1))) {
			System.out.println(total+caca.get(caca.size()-1));
		} else {
			System.out.println((total-caca.get(caca.size()-1))-min*2);
		}
	}
}

class FastScanner {
	BufferedReader br;
	StringTokenizer st;

	public FastScanner(String s) {
		try {
			br = new BufferedReader(new FileReader(s));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public FastScanner() {
		br = new BufferedReader(new InputStreamReader(System.in));
	}

	ArrayList<Integer>[] ng(int n, int e) {
		ArrayList<Integer>[] adj = new ArrayList[n];
		for (int i = 0; i < n; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for (int i = 0; i < e; i++) {
			int a = ni() - 1;
			int b = ni() - 1;
			adj[a].add(b);
			adj[b].add(a);
		}
		return adj;
	}

	Integer[] nIa(int n) {
		Integer[] arr = new Integer[n];
		for (int i = 0; i < n; i++) {
			arr[i] = ni();
		}
		return arr;
	}

	int[] nia(int n) {
		int[] arr = new int[n];
		for (int i = 0; i < n; i++) {
			arr[i] = ni();
		}
		return arr;
	}

	Long[] nLa(int n) {
		Long[] arr = new Long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nl();
		}
		return arr;
	}

	long[] nla(int n) {
		long[] arr = new long[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nl();
		}
		return arr;
	}

	String[] nsa(int n) {
		String[] arr = new String[n];
		for (int i = 0; i < n; i++) {
			arr[i] = nt();
		}
		return arr;
	}

	String nt() {
		while (st == null || !st.hasMoreElements()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		return st.nextToken();
	}

	int ni() {
		return Integer.parseInt(nt());
	}

	long nl() {
		return Long.parseLong(nt());
	}

	double nd() {
		return Double.parseDouble(nt());
	}

}
