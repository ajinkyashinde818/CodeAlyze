import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        init();

        long n = nextLong();
        if (n % 2 == 1) {
            System.out.println(0);
            return;
        }

        long numOf10s = 0;

        long p10 = 1;
        while (n >= p10) {
            p10 *= 5;
            numOf10s += (n/p10)/2;
        }

        System.out.println(numOf10s);
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

    private static long nextLong() throws IOException {
        return Long.parseLong(next());
    }
}
