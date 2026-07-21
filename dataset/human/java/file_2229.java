import java.util.*;
import java.io.*;

public class Main {
    static StringTokenizer st;
    static BufferedReader br;  
    static PrintWriter out;
 
    static int parent[]; 

    public static void main(String[] args) throws IOException {
        br = new BufferedReader(new InputStreamReader(System.in));
 
        long N = nextLong();
        
        HashMap<Long,Integer> map = new HashMap<Long,Integer>();
 
        for (int x=2; x<=Math.sqrt(N); x++) {  
            while(N % x==0){
                map.put((long) x, map.getOrDefault((long)x,0)+1);
                N = N / x;
            }
        }
        if(N!=1){
            map.put(N, map.getOrDefault(N,0)+1);
        }

        int ansList[] = new int[11]; //enough
        for (int x=1; x<=10; x++) {  
            ansList[x] = ansList[x-1] + x; 
        }

        int ans = 0;
        for (Map.Entry<Long,Integer> entry: map.entrySet()) {
            int temp =  entry.getValue();
            int index = Arrays.binarySearch(ansList, temp);
            if(index<0){
                index = -index-2;
            }
            ans += index;
        }

        System.out.println(ans);
    
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
