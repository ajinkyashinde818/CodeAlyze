import java.io.*;
import java.util.*;
import java.lang.*;

public class Main {
    static class FastReader
        {
            BufferedReader br;
            StringTokenizer st;

            public FastReader()
            {
                br = new BufferedReader(new
                        InputStreamReader(System.in));
            }

            String next()
            {
                while (st == null || !st.hasMoreElements())
                {
                    try
                    {
                        st = new StringTokenizer(br.readLine());
                    }
                    catch (IOException e)
                    {
                        e.printStackTrace();
                    }
                }
                return st.nextToken();
            }

            int nextInt()
            {
                return Integer.parseInt(next());
            }

            long nextLong()
            {
                return Long.parseLong(next());
            }

            double nextDouble()
            {
                return Double.parseDouble(next());
            }

            String nextLine()
            {
                String str = "";
                try
                {
                    str = br.readLine();
                }
                catch (IOException e)
                {
                    e.printStackTrace();
                }
                return str;
            }
        }
    public static void main(String[] args) {
        FastReader ob = new FastReader();
        int k =ob.nextInt(),n=ob.nextInt();
        int arr[] =  new int[n];
        int max_diff=-1,start=0,end=0;
        long sum=0;
        arr[0]=ob.nextInt();
        for (int i = 1; i < n; i++) {
            arr[i]=ob.nextInt();
            sum+=(arr[i]-arr[i-1]);
            max_diff=Math.max(arr[i]-arr[i-1],max_diff);
        }
        max_diff=Math.max(k-arr[n-1]+arr[0],max_diff);
        sum+=k-arr[n-1]+arr[0];
        System.out.println(sum-max_diff);



    }
}
