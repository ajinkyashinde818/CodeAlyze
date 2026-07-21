import java.util.*;
import java.io.*;

public class Main {
    static StringTokenizer st;
    static BufferedReader br;  
    static PrintWriter out;
 
    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
 
        int N = nextInt();
        long K = nextLong();
        
        int[] map = new int[N+1];
        
        for(int i = 1; i<=N; i++){
            map[i] = nextInt();
        }

        int[] count = new int[N+1];
        int[] Indexstep = new int[N+1];
        int[] stepIndxe = new int[N+1];
        
        count[1]= 1; // start from 1
        int next = map[1];
        Indexstep[1] = 0;   
        stepIndxe[0] = 1;
        for(int i = 1; i<=N; i++){
            count[next]++;
            if(count[next]>1){
                // here is the loop
                int mod = i - Indexstep[next]; 
                long k = (K-Indexstep[next]) % mod + Indexstep[next]; 
                if(K<=Indexstep[next]){
                    k=K;
                }
                System.out.println(stepIndxe[(int)k]);

                return;
            }
            else {
                Indexstep[next] = i; 
                stepIndxe[i] = next;  
            }
            next= map[next];

        }

 
 
        
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
