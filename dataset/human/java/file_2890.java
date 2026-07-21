import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;

class Main {

    public static void main(String[] args) throws IOException {
        doit(args, System.in, System.out);
    }

    static void doit(String[] args, InputStream in, PrintStream out)
            throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(in));
        String line = null;
        while ((line = reader.readLine()) != null) {
            if (line.isEmpty()) {
                continue;
            }
            String[] values = line.split(" ");
            int[] ps = new int[8];
            for (int i = 0; i < 8; i++) {
                ps[i] = Integer.parseInt(values[i]);
            }
            int maxCount = 0;
            int maxIndex = 0;
            for (int i = 0; i < 8; i++) {
                int count = 0;
                for (int j = 0; j < 8; j++) {
                    count += Math.min(cs[i][j], ps[j]);
                }
                if (count > maxCount) {
                    maxCount = count;
                    maxIndex = i;
                }
            }
            out.print(cs[maxIndex][0]);
            for (int i = 1; i < 8; i++) {
                out.print(" " + cs[maxIndex][i]);
            }
            out.println();
        }
    }

    private static final int[][] cs = { { 1, 2, 1, 2, 1, 4, 1, 4 },
            { 1, 2, 1, 4, 1, 4, 1, 2 }, { 1, 4, 1, 2, 1, 2, 1, 4 },
            { 1, 4, 1, 4, 1, 2, 1, 2 }, { 2, 1, 2, 1, 4, 1, 4, 1 },
            { 2, 1, 4, 1, 4, 1, 2, 1 }, { 4, 1, 2, 1, 2, 1, 4, 1 },
            { 4, 1, 4, 1, 2, 1, 2, 1 }, };
}
