import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.*;


public class Main {
    
         
    static FastReader in;
    static StringBuilder out;

    public  static void main(String[] args) {
        
        in = new FastReader();
        out=new StringBuilder();
        int k=in.nextInt(),n=in.nextInt();
        int dis[]=new int[n];
        for(int i=0;i<n;i++){
            dis[i]=in.nextInt();
        }
        Arrays.sort(dis);
        int ans=Math.min(Math.abs(dis[dis.length-1]-dis[0]),k-Math.abs(dis[1]-dis[0]));
        for(int i=1;i<n;i++){
            int clk=0,aclk=0;
            clk=k-Math.abs(dis[i]-dis[i-1]);
            if(i==n-1){
                aclk=Math.abs(dis[n-1]-dis[0]);
            }else{
                aclk=k-Math.abs(dis[i+1]-dis[i]);
            }
            ans=Math.min(Math.min(clk, aclk),ans);
        }
        System.out.println(ans);
    }
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader() {
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
