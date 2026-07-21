import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main
{
    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
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
    public static void main(String args[])
    {
        FastReader obj = new FastReader();
        int dist = obj.nextInt(),house = obj.nextInt(),no_house[] = new int[house];
        for(int i=0;i<house;i++) no_house[i] = obj.nextInt();
        int find[] = new int[house];
        for(int i=0;i<house;i++)
        {
            if(i==0)
                find[i] = no_house[no_house.length-1]-no_house[i];
            else
                find[i] = (dist-no_house[i])+no_house[i-1];
        }
        int min = Integer.MAX_VALUE;
        for(int i=0;i<house;i++) min = Math.min(find[i],min);
        System.out.println(min);
    }
}
