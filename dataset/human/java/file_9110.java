import java.util.*;
import java.io.*;
import java.lang.*;

public final class Main {

    private final static boolean USE_FILE_IO = false;
    private final static int m = 1_000_000_007;

    void solve() throws java.lang.Exception {
        int n = ri();
        int[] a = ria();
        int k = a.length;
        int s1 = 0, s2 = 1;
        int j = 0;
        for (int i=1; i<=n; i++) {
            int s3 = 0;
            if (j<k && i==a[j]) j++;
            else s3 = (s1 + s2) % m;
            s1 = s2;
            s2 = s3;
        }
        wr(s2);
    }

    long diff(long b, long x, long l, long u) {
        return (x-b) * u - (u - b) * l;
    }

    public static void main(String[] args) throws java.lang.Exception {
        Reader reader = null;
        Writer writer = null;
        try {
            if (USE_FILE_IO) {
                reader = new Reader(new FileInputStream("input.txt"));
                writer = new Writer(new FileOutputStream("output.txt"));
            } else {
                reader = new Reader(System.in);
                writer = new Writer(System.out);
            }            
            new Main(reader, writer).solve();
        } finally {
            if (reader != null)
                reader.close();
            if (writer != null)
                writer.close();
        }
    }

    Reader reader;
    Writer writer;

    Main(Reader reader, Writer writer) {
        this.reader = reader;
        this.writer = writer;
    }

    int ri() throws java.lang.Exception {
        return reader.nextInt();
    }

    int[] ria() throws java.lang.Exception {
        int n = ri();
        int[] a = new int[n];
        for (int i=0; i<n; i++) a[i] = ri();
        return a;
    }

    long rl() throws java.lang.Exception {
        return reader.nextLong();
    }

    long[] rla() throws java.lang.Exception {
        int n = ri();
        long[] a = new long[n];
        for (int i=0; i<n; i++) a[i] = rl();
        return a;
    }

    double rd() throws java.lang.Exception {
        return reader.nextDouble();
    }

    String rs() {
        return reader.nextToken();
    }

    String rline()  throws java.lang.Exception {
        return reader.nextLine();
    }

    void wr(int x)  throws java.lang.Exception {
        writer.write(x);
    }

    void wr(int[] a)  throws java.lang.Exception {
        for (int i=0; i<a.length; i++) {
            if (i!=0) wr(" ");
            wr(a[i]);
        }
        wl();
    }

    void wr(long x)  throws java.lang.Exception {
        writer.write(x);
    }

    void wr(long[] a)  throws java.lang.Exception {
        for (int i=0; i<a.length; i++) {
            if (i!=0) wr(" ");
            wr(a[i]);
        }
        wl();
    }

    void wr(double x)  throws java.lang.Exception {
        writer.write(x);
    }    

    void wr(String s)  throws java.lang.Exception {
        writer.write(s);
    }

    void wl()  throws java.lang.Exception {
        writer.writeLine();
    }

    void wline(String s)  throws java.lang.Exception {
        writer.writeLine(s);
    }

    static class Writer {
        BufferedWriter bw;

        public Writer(OutputStream out) {
            bw = new BufferedWriter(new OutputStreamWriter(out));
        }

        void write(String s) throws java.lang.Exception {
            bw.write(s);
        }

        void write(int x) throws java.lang.Exception {
            write(String.valueOf(x));
        }

        void write(long x) throws java.lang.Exception {
            write(String.valueOf(x));
        }

        void write(double x) throws java.lang.Exception {
            write(String.valueOf(x));
        }

        void write(char c) throws java.lang.Exception {
            bw.write(c);
        }

        void newLine() throws java.lang.Exception {
            bw.newLine();
        }

        void writeLine(String s) throws java.lang.Exception {
            write(s);
            newLine();
        }

        void writeLine(int n) throws java.lang.Exception {
            writeLine(String.valueOf(n));
        }

        void writeLine(long n) throws java.lang.Exception {
            writeLine(String.valueOf(n));
        }
        
        void writeLine() throws java.lang.Exception {
            writeLine("");
        }

        void close() throws java.lang.Exception {
            bw.flush();
            bw.close();
        }
    }

    static class Reader {
        BufferedReader br;
        StringTokenizer st;

        public Reader(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }

        String nextToken() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        String[] nextTokens(int n) {
            String[] a = new String[n];
            for (int i=0; i<n; i++) {
                a[i] = nextToken();
            }
            return a;
        }

        int nextInt() {
            return Integer.parseInt(nextToken());
        }

        int[] nextInts(int n) {
            int[] a = new int[n];
            for (int i=0; i<n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        long nextLong() {
            return Long.parseLong(nextToken());
        }

        long[] nextLongs(int n) {
            long[] a = new long[n];
            for (int i=0; i<n; i++) {
                a[i] = nextInt();
            }
            return a;
        }

        double nextDouble() {
            return Double.parseDouble(nextToken());
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

        void close() throws java.lang.Exception {
            br.close();
        }
    }
}
