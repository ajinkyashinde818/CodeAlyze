import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        FastReader s = new FastReader();
        int K = s.nextInt();
        int N=s.nextInt();
        int [] arr = new int[N];
        for(int i=0;i<N;i++)
            arr[i]=s.nextInt();
        int [] arrCost = new int[N];
        for(int i=0;i<N-1;i++){
            arrCost[i]=arr[i+1]-arr[i];
        }
         arrCost[N-1]=K+arr[0]-arr[N-1];
        int max=Integer.MIN_VALUE;
        int totalCost=0;
        for(int i=0;i<N;i++){
            if(arrCost[i]>=max)
                max=arrCost[i];
            totalCost+=arrCost[i];
        }
        System.out.println(totalCost-max);
    }

    private static boolean isPrime(int n) {
        if (n == 2)
            return true;
        else if ((n % 2 == 0 && n > 2) || n < 2)
            return false;
        else {
            for (int i = 3; i <= (int) Math.sqrt(n); i += 2) {
                if (n % i == 0)
                    return false;
            }
            return true;
        }


    }

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
}
