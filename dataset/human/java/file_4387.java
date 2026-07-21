import java.io.*;
import java.util.*;

@SuppressWarnings("unused")
public class Main {
    FastScanner in = new FastScanner(System.in);
    PrintWriter out = new PrintWriter(System.out);
    final int MOD = (int)1e9+7;
    long dup(long a, long b){return (a + b - 1) / b;}
    void printlnYN(boolean b){out.println((b ? "Yes" : "No"));}

    void solve() throws Exception{
        solveB();
    }

    void solveA() throws Exception{
        int N = in.nextInt();
        out.println(N*N*N);
    }

    void solveB() throws Exception{
        int N = in.nextInt();
        long sum = 0;
        int[] A = new int[N], C = new int[N];
        for(int i = 0; i < N; i++) A[i] = in.nextInt()-1;
        for(int i = 0; i < N; i++) sum += in.nextInt();
        for(int i = 0; i < N-1; i++) C[i] = in.nextInt();
        for(int i = 0; i < N-1; i++){
            if(A[i+1] == A[i] + 1) sum += C[A[i]];
        }
        out.println(sum);
    }

    void solveC() throws Exception{
        int N = in.nextInt();
        int[] B = new int[N];
        for(int i = 0; i < N-1; i++) B[i] = in.nextInt();
        int[] A = new int[N];
        long sum = B[N-2] + B[0];
        for(int i = N-2; i >= 0; i--){
            A[i] = Math.min(B[i+1], B[i]);
            sum += A[i];
        }
        out.println(sum);
    }

    void solveD() throws Exception{
        int N = in.nextInt(), K = in.nextInt();
        char c = 'x';
        String S = in.nextStr();
        int num = 0, sum = 0, len = 1;

        for(char e : S.toCharArray()){
            if(e != c){
                num++;
                sum += len-1;
                len = 1;
            }else{
                len++;
            }
            c = e;
        }
        sum += len-1;

        for(int i = 0; i < K; i++){
            if(num > 3){
                num -= 2;
                sum += 2;
            }else if(num == 2){
                num -= 1;
                sum += 1;
            }else{
                break;
            }
        }
        out.println(sum);
    }

    void solveE() throws Exception{
        int N = in.nextInt();
        int[] P = new int[N], index = new int[N];
        for (int i = 0; i < N; i++) {
            P[i] = in.nextInt();
            index[P[i]-1] = i;
        }

        TreeSet<Integer> set = new TreeSet<>();
        long sum = 0;
        for (int i = N-1; i >= 0; i--) {
            Integer L1 = set.lower(index[i]);
            Integer L2 = null;
            if(L1 != null) L2 = set.lower(L1);
            Integer R1 = set.higher(index[i]);
            Integer R2 = null;
            if(R1 != null) R2 = set.higher(R1);
            if(L1 == null) L1 = -1;
            if(L2 == null) L2 = -1;
            if(R1 == null) R1 = N;
            if(R2 == null) R2 = N;

            long num = 0;
            num += (L1 - L2) * (R1 - index[i]);
            num += (index[i] - L1) * (R2 - R1);
            sum += num * (i+1);
            //out.println(L1 + " " + L2 + " " + R1 + " " + R2);
            //out.println((L1 - L2) + " " + (R1 - index[i]) + " " + (index[i] - L1) + " " + (R2 - R1));
            set.add(index[i]);
        }
        out.println(sum);
    }

    public static void main(String[] args) throws Exception {
        new Main().m();
    }

    void m() throws Exception {
        solve();
        out.flush();
    }

    static class FastScanner {
        Reader input;

        FastScanner() {this(System.in);}
        FastScanner(InputStream stream) {this.input = new BufferedReader(new InputStreamReader(stream));}

        int nextInt() {return (int) nextLong();}

        long nextLong() {
            try {
                int sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                long ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) return ret * sign;
                    ret *= 10;
                    ret += b - '0';
                }
            } catch (IOException e) {
                e.printStackTrace();
                return -1;
            }
        }

        double nextDouble() {
            try {
                double sign = 1;
                int b = input.read();
                while ((b < '0' || '9' < b) && b != '-' && b != '+') {
                    b = input.read();
                }
                if (b == '-') {
                    sign = -1;
                    b = input.read();
                } else if (b == '+') {
                    b = input.read();
                }
                double ret = b - '0';
                while (true) {
                    b = input.read();
                    if (b < '0' || '9' < b) break;
                    ret *= 10;
                    ret += b - '0';
                }
                if (b != '.') return sign * ret;
                double div = 1;
                b = input.read();
                while ('0' <= b && b <= '9') {
                    ret *= 10;
                    ret += b - '0';
                    div *= 10;
                    b = input.read();
                }
                return sign * ret / div;
            } catch (IOException e) {
                e.printStackTrace();
                return Double.NaN;
            }
        }

        char nextChar() {
            try {
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                return (char) b;
            } catch (IOException e) {
                e.printStackTrace();
                return 0;
            }
        }

        String nextStr() {
            try {
                StringBuilder sb = new StringBuilder();
                int b = input.read();
                while (Character.isWhitespace(b)) {
                    b = input.read();
                }
                while (b != -1 && !Character.isWhitespace(b)) {
                    sb.append((char) b);
                    b = input.read();
                }
                return sb.toString();
            } catch (IOException e) {
                e.printStackTrace();
                return "";
            }
        }

        public int[] nextIntArray(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt();
            }
            return res;
        }

        public int[] nextIntArrayDec(int n) {
            int[] res = new int[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextInt() - 1;
            }
            return res;
        }

        public int[] nextIntArray1Index(int n) {
            int[] res = new int[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextInt();
            }
            return res;
        }

        public long[] nextLongArray(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public long[] nextLongArrayDec(int n) {
            long[] res = new long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong() - 1;
            }
            return res;
        }

        public long[] nextLongArray1Index(int n) {
            long[] res = new long[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextLong();
            }
            return res;
        }

        public double[] nextDoubleArray(int n) {
            double[] res = new double[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextDouble();
            }
            return res;
        }

        public Long[] nextWrapperLongArray(int n) {
            Long[] res = new Long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong();
            }
            return res;
        }

        public Long[] nextWrapperLongArrayDec(int n) {
            Long[] res = new Long[n];
            for (int i = 0; i < n; i++) {
                res[i] = nextLong() - 1;
            }
            return res;
        }

        public Long[] nextWrapperLongArray1Index(int n) {
            Long[] res = new Long[n + 1];
            for (int i = 0; i < n; i++) {
                res[i + 1] = nextLong();
            }
            return res;
        }
    }
}
