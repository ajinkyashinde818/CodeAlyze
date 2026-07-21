import java.util.*;
import java.io.*;

public class Main {	
	public static void main(String[] args) {
		FastScanner fs = new FastScanner();
        int K = fs.nextInt();
        int N = fs.nextInt();
        List<Integer> list = new ArrayList<>();
        long max = 0;

        for(int i=0; i<N; i++){
            int dis = fs.nextInt();
            list.add(dis);
        }

        if(list.contains(0)){
            max = K-list.get(N-1);
        }else{
            max = K-list.get(N-1)+list.get(0);
        }

        for(int i=1; i<N; i++){
            long distance = list.get(i)-list.get(i-1);
            if(distance>max){
                max = distance;
            }
        }
        
		System.out.println(K-max);
	}

	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");

		public String next() {
			while (!st.hasMoreElements())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}

		public int nextInt() {
			return Integer.parseInt(next());
		}

		public long nextLong() {
			return Long.parseLong(next());
		}

		public int[] readArray(int n) {
			int[] a=new int[n];
			for (int i=0; i<n; i++) {
				a[i]=nextInt();
			}
			return a;
		}

		public double nextDouble() {
			return Double.parseDouble(next());
		}

	}
}
