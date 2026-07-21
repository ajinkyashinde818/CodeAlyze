import java.io.*;
import java.util.Optional;
import java.util.StringJoiner;
import java.util.StringTokenizer;

public class Main {

    static int N;

    public static void main(String[] args) {
        FastScanner sc = new FastScanner(System.in);
        N = sc.nextInt();

        Answer answer = solve();
        PrintWriter pw = new PrintWriter(System.out);
        if( answer != null ) {
            pw.println("Yes");
            pw.println(String.valueOf(answer.SS.length));
            for (int[] S : answer.SS) {
                StringJoiner j = new StringJoiner(" ");
                j.add(String.valueOf(S.length));
                for (int s : S) {
                    j.add(String.valueOf(s));
                }
                pw.println(j.toString());
            }
        } else {
            System.out.println("No");
        }
        pw.flush();
    }

    static Answer solve() {
        Optional<Integer> m = isOk();
        if( m.isPresent() ) {
            return calc(m.get());
        } else {
            return null;
        }
    }

    static Optional<Integer> isOk() {
        int sum = 0;
        int i = 1;
        while(true) {
            sum += i;
            if( sum == N ) return Optional.of(i);
            if( sum > N ) return Optional.empty();
            i++;
        }
    }

    static Answer calc(int len) {
        int size = N*2 / len;
        int[][] ss = new int[size][len];
        int cur = 1;
        for (int i = 0; i < len; i++) {
            ss[0][i] = cur++;
        }

        for (int i = 1; i < size; i++) {
            int prevSize = i;
            int prevIdx = i-1;
            // lenのうち, len-size分が自前、それ以外は以前のものから取得
            // 1 2 3
            // 1     4 5
            //   2   4   6
            //     3   5 6
            for (int j = 0; j < prevSize; j++) {
                ss[i][j] = ss[j][prevIdx];
            }

            int newSize = len - prevSize;
            for (int j = 0; j < newSize; j++) {
                ss[i][j+prevSize] = cur++;
            }
        }
        return new Answer(ss);
    }

    static class Answer {
        int[][] SS;

        public Answer(int[][] SS) {
            this.SS = SS;
        }
    }

    @SuppressWarnings("unused")
    static class FastScanner {
        private BufferedReader reader;
        private StringTokenizer tokenizer;

        FastScanner(InputStream in) {
            reader = new BufferedReader(new InputStreamReader(in));
            tokenizer = null;
        }

        String next() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        String nextLine() {
            if (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    return reader.readLine();
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken("\n");
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = nextInt();
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = nextLong();
            return a;
        }
    }
}
