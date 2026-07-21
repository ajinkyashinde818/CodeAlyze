import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        init();

        int N = nextInt(), M = nextInt();
        Set<Integer> vals = new HashSet<>();
        for (int i = 0; i < M; i++) vals.add(nextInt());

        long mod = 1000000007;
        long[] ways = new long[N + 1];

        ways[0] = 1;

        for (int i = 1; i < ways.length; i++) {
            if (vals.contains(i)) ways[i] = 0;
            else ways[i] = (ways[i - 1] + (i - 2 >= 0 ? ways[i - 2] : 0)) % mod;
        }

        System.out.println(ways[N]);
    }

    //Input Reader
    private static BufferedReader reader;
    private static StringTokenizer tokenizer;

    private static void init() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        tokenizer = new StringTokenizer("");
    }

    private static String next() throws IOException {
        String read;
        while (!tokenizer.hasMoreTokens()) {
            read = reader.readLine();
            if (read == null || read.equals(""))
                return "-1";
            tokenizer = new StringTokenizer(read);
        }

        return tokenizer.nextToken();
    }

    private static int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
}
