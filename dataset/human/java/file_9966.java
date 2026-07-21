import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static long min=Long.MAX_VALUE;
    static int n,m,x;
    static int price[];
    static int increment[][];

    public static void main(String[] args) throws IOException {
        Scanner s = new Scanner(System.in);
         n = s.nextInt();m=s.nextInt();x=s.nextInt();
        price = new int[n];
        increment = new int[n][m];
        for(int i=0;i<n;i++){
            price[i]=s.nextInt();
            for(int j=0;j<m;j++)increment[i][j]=s.nextInt();
        }
        arr = new ArrayList<>();
        solve(0,0L);
        if(min==Long.MAX_VALUE)System.out.println(-1);
        else System.out.println(min);
    }

    static ArrayList<Integer> arr ;

    public static void solve(int i,long sum){
        if(i==n){
            long algo[] = new long[m];
            for(int j=0;j<arr.size();j++){
                int u = arr.get(j);
                for(int o=0;o<m;o++)algo[o]+=increment[u][o];
            }
            boolean flag = true;
            for(int j=0;j<m;j++){
                if(algo[j]<x){
                    flag=false;
                    break;
                }
            }
            if(flag)min=Math.min(min,sum);

        }
        else{
            arr.add(i);
            solve(i+1,sum+price[i]);
            arr.remove(arr.size()-1);
            solve(i+1,sum);
        }
    }
}




class Scanner
{
    StringTokenizer st;
    BufferedReader br;

    public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

    public String next() throws IOException
    {
        while (st == null || !st.hasMoreTokens())
            st = new StringTokenizer(br.readLine());
        return st.nextToken();
    }

    public int nextInt() throws IOException {return Integer.parseInt(next());}

    public long nextLong() throws IOException {return Long.parseLong(next());}

    public String nextLine() throws IOException {return br.readLine();}

    public double nextDouble() throws IOException
    {
        String x = next();
        StringBuilder sb = new StringBuilder("0");
        double res = 0, f = 1;
        boolean dec = false, neg = false;
        int start = 0;
        if(x.charAt(0) == '-')
        {
            neg = true;
            start++;
        }
        for(int i = start; i < x.length(); i++)
            if(x.charAt(i) == '.')
            {
                res = Long.parseLong(sb.toString());
                sb = new StringBuilder("0");
                dec = true;
            }
            else
            {
                sb.append(x.charAt(i));
                if(dec)
                    f *= 10;
            }
        res += Long.parseLong(sb.toString()) / f;
        return res * (neg?-1:1);
    }

    public boolean ready() throws IOException {return br.ready();}


}
