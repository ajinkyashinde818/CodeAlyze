import java.io.*;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws IOException {
        init();

        int k = nextInt(), n = nextInt();
        int[] houses = new int[n];
        for (int i = 0; i < n; i++) {
            houses[i] = nextInt();
        }

        int minDistance = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int last = i == 0 ? n - 1 : i - 1;
            int point = last == n - 1 ? houses[last] : houses[last] + k;
            minDistance = Math.min(point - houses[i], minDistance);
        }

        System.out.println(minDistance);
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
