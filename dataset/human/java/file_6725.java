import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws java.lang.Exception {
		MyScanner sc = new MyScanner();
		out = new PrintWriter(new BufferedOutputStream(System.out));

		String input[] = sc.nextLine().split(" ");
		int k = Integer.parseInt(input[0]);
		int n = Integer.parseInt(input[1]);
		int ar[] = new int[n];
		String input2[] = sc.nextLine().split(" ");
		for(int i = 0; i < n; i++)
			ar[i] = Integer.parseInt(input2[i]);
		int tour[] = new int[(2 * n) - 1];
		for(int i = 0; i < n; i++)
			tour[i] = ar[i];
		
		for(int i = 0; i < n - 1; i++)
			tour[i + n] = ar[i] + k;
		
		/*for(int i = 0; i < tour.length; i++)
			System.out.print(tour[i] + " ");
		
		System.out.println();*/
		int distance = 0;
		for(int i = 1; i < n; i++)
			distance = distance + (tour[i] - tour[i - 1]);
		//System.out.println(distance);
		int mindistance = distance;
		
		for(int i = 1; i < n; i++) {
			distance = distance - Math.abs(ar[i] - ar[i - 1]);
			distance = distance + Math.abs((tour[i + n -1] - tour[i + n -2]));
			//System.out.println(ar[i]+" : " +distance+ " ");
			mindistance = Math.min(distance, mindistance);
		}
		System.out.println(mindistance);
		out.close();
	}

	public static PrintWriter out;

	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}

	}

}
