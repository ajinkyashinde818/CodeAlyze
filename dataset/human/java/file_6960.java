import java.io.*;
import java.util.*;

//solution classes here

public class Main {

    //main solution here

    static Scanner sc = new Scanner(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) throws IOException {
        long k = sc.nextLong();
        int n = sc.nextInt();
        long a[] = new long[n];
        for(int i=0;i<n;i++)
            a[i]=sc.nextLong();
        long diff[] = new long[n];
        for(int i=0;i<n-1;i++) {
            diff[i]=a[i+1]-a[i];
        }
        diff[n-1] = k+a[0]-a[n-1];
        Arrays.sort(diff);
        long sum=0;
        for(int i=0;i<n-1;i++)
            sum+=diff[i];
        out.println(sum);


        out.flush();
        out.close();
    }

    //solution functions here


    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader fileReader) {
            br = new BufferedReader(fileReader);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}

/* *****************************************************************************************************************************
 * I'M NOT IN DANGER, I'M THE DANGER!!!
 * *****************************************************************************************************************************
 */
