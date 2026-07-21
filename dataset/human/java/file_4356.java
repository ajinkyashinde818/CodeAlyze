import java.io.*;
import java.util.*;

public class Main {

    private static int[][] st;
    private static int [] logs;
    public static void main(String[] args) throws IOException {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        InputReader.OutputWriter out = new InputReader.OutputWriter(outputStream);
        Scanner scanner = new Scanner(System.in);

        int n = in.nextInt();
        int [] a = new int[n];
        int [] b = new int[n];
        int [] c = new int [n-1];
        for (int i = 0; i < a.length; i++) {
            a[i] = in.nextInt();
        }
        for (int i = 0; i < b.length; i++) {
            b[i] = in.nextInt();
        }
        for (int i = 0; i < c.length; i++) {
            c[i] = in.nextInt();
        }
        int sum = 0;
        int previous = -1;
        for (int i = 0; i < n; i++) {
            int dish = a[i];
            dish--;
            sum+=b[dish];
            if(previous!=-1) {
                if (dish - previous == 1) {
                    sum += c[previous];
                }
            }
            previous = dish;

        }
        out.println(sum);


        out.flush();
    }

    private static boolean can(int [] a, int k) {
        int n = a.length;
        int l = n/k;
        int ostatok = n%k;
        if(ostatok!=0) {
            l++;
            for (int i = 0; i < ostatok; i++) {
                if(k-l<a[i]) return false;
            }
            for (int i = ostatok + 1; i < n; i++) {
                if(k-l+1<a[i]) return false;
            }
            return true;
        }
        else {
            for (int i = 0; i < n; i++) {
                if(k-l<a[i]) return false;
            }
            return true;
        }
    }
    public void fillSt(int []a,int n) {
        logs = new int[n+1];
        logs[1] = 0;
        for (int i = 2; i <=n; i++) {
            logs[i] = logs[i/2] + 1;
        }
        st = new int[30][n];
        for (int i = 0; i <= logs[n]; i++) {
            int curLen = 1 << i;
            for (int j = 0; j+curLen <=n; j++) {
                if(curLen == 1) {
                    st[i][j] = a[j];
                }
                else {
                    st[i][j] = Math.max(st[i-1][j],st[i-1][j+(curLen/2)]);
                }
            }
        }

    }
    static int getMin(int l, int r) {
        int p = logs[r-l+1];
        int pLen = 1<<p;
        return Math.max(st[p][l],st[p][r-pLen+1]);
    }
    static int numberOfSubsequences(String a, String b) {
        int [] dp = new int[b.length()+1];
        dp[0] = 1;
        for (int i = 0; i < a.length(); i++) {
            for (int j = b.length() - 1; j >=0;j--) {
                if(a.charAt(i) == b.charAt(j)) {
                    dp[j+1]+=dp[j];
                }
            }
        }
        return dp[dp.length - 1];
    }
    static long count(String a, String b)
    {
        int m = a.length();
        int n = b.length();

        // Create a table to store
        // results of sub-problems
        long lookup[][] = new long[m + 1][n + 1];

        // If first string is empty
        for (int i = 0; i <= n; ++i)
            lookup[0][i] = 0;

        // If second string is empty
        for (int i = 0; i <= m; ++i)
            lookup[i][0] = 1;

        // Fill lookup[][] in
        // bottom up manner
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // If last characters are
                // same, we have two options -
                // 1. consider last characters
                //    of both strings in solution
                // 2. ignore last character
                //    of first string
                if (a.charAt(i - 1) == b.charAt(j - 1))
                    lookup[i][j] = lookup[i - 1][j - 1] +
                            lookup[i - 1][j];

                else
                    // If last character are
                    // different, ignore last
                    // character of first string
                    lookup[i][j] = lookup[i - 1][j];
            }
        }

        return lookup[m][n];
    }
}
class Point {
    private int x;
    private int y;
    public int getX() {
        return x;
    }
    public int getY() {
        return y;
    }
    public Point(int x,int y) {
        this.x = x;
        this.y = y;
    }
    public long dest() {
        return this.getX()*this.getX() + this.getY()*this.getY();
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Point point = (Point) o;
        return x == point.x &&
                y == point.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}

class InputReader extends BufferedReader {
    StringTokenizer tokenizer;

    public InputReader(InputStream inputStream) {
        super(new InputStreamReader(inputStream), 32768);
    }

    public InputReader(String filename) {
        super(new InputStreamReader(Thread.currentThread().getContextClassLoader().getResourceAsStream(filename)));
    }

    public String next() {
        while (tokenizer == null || !tokenizer.hasMoreTokens()) {
            try {
                tokenizer = new StringTokenizer(readLine());
            } catch (IOException e) {
                throw new RuntimeException();
            }
        }
        return tokenizer.nextToken();
    }

    public Integer nextInt(){
        return Integer.valueOf(next());
    }
    public Long nextLong() {
        return  Long.valueOf(next());
    }
    public Double nextDouble() {
        return Double.valueOf(next());
    }
    static class OutputWriter extends PrintWriter {
        public OutputWriter(OutputStream outputStream) {
            super(outputStream);
        }

        public OutputWriter(Writer writer) {
            super(writer);
        }

        public OutputWriter(String filename) throws FileNotFoundException {
            super(filename);
        }

        public void close() {
            super.close();
        }
    }
}
