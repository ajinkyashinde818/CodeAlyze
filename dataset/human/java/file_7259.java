import java.util.*; 
import java.io.*;

public class Main{
    static StringTokenizer st;
    static BufferedReader br;  
    static PrintWriter out;
 
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
 
        int K = nextInt();
        int N = nextInt();

        int[] input = new int[N];
        for (int x=0; x<N; x++) { 
            input[x]  = nextInt();
        }

        Arrays.sort(input);

        int max = Integer.MIN_VALUE;
        
        for (int x=1; x<N; x++) { 
            int tmp = input[x] - input[x-1]; 
            max = Math.max(tmp, max);
        }

        max = Math.max(K-input[N-1]+input[0], max);

        System.out.println(K-max);
    }
    
      
    public static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    public static long nextLong() throws IOException {
        return Long.parseLong(next());
    }

    public static double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }

    static String next() throws IOException {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine().trim());
        return st.nextToken();
    }
}
