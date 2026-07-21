import java.io.*;
import java.util.*;

class FastScanner {
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;
    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        }else{
            ptr = 0;
            try {
                buflen = in.read(buffer);
            } catch (IOException e) {
                e.printStackTrace();
            }
            if (buflen <= 0) {
                return false;
            }
        }
        return true;
    }
    private int readByte() { if (hasNextByte()) return buffer[ptr++]; else return -1;}
    private static boolean isPrintableChar(int c) { return 33 <= c && c <= 126;}
    public boolean hasNext() { while(hasNextByte() && !isPrintableChar(buffer[ptr])) ptr++; return hasNextByte();}
    public String next() {
        if (!hasNext()) throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while(isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }
    public long nextLong() {
        if (!hasNext()) throw new NoSuchElementException();
        long n = 0;
        boolean minus = false;
        int b = readByte();
        if (b == '-') {
            minus = true;
            b = readByte();
        }
        if (b < '0' || '9' < b) {
            throw new NumberFormatException();
        }
        while(true){
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            }else if(b == -1 || !isPrintableChar(b)){
                return minus ? -n : n;
            }else{
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
    public int nextInt() {
        long nl = nextLong();
        if (nl < Integer.MIN_VALUE || nl > Integer.MAX_VALUE) throw new NumberFormatException();
        return (int) nl;
    }
    public double nextDouble() { return Double.parseDouble(next());}
}

class Main{
        
    static FastScanner scan = new FastScanner();
    static final int MOD = 1_000_000_007;
    static final int INF = 2147483647;
    static final long LINF = 9223372036854775807L;

    // Scanner
    int ni(){return scan.nextInt();}
    int[] ni(int n){int[] a = new int[n]; for(int i = 0; i < n; i++){a[i] = ni();} return a;}
    int[][] ni(int y, int x){int[][] a = new int[y][x];
        for(int i = 0; i < y; i++){for(int j = 0; j < x; j++){a[i][j] = ni();}} return a;}
    long nl(){return scan.nextLong();}
    long[] nl(int n){long[] a = new long[n]; for(int i = 0; i < n; i++){a[i] = nl();} return a;}
    long[][] nl(int y, int x){long[][] a = new long[y][x];
        for(int i = 0; i < y; i++){for(int j = 0; j < x; j++){a[i][j] = nl();}} return a;}
    String ns(){return scan.next();}
    String[] ns(int n){String[] a = new String[n]; for(int i = 0; i < n; i++){a[i] = ns();} return a;}
    String[][] ns(int y, int x){String[][] a = new String[y][x];
        for(int i = 0; i < y; i++){for(int j = 0; j < x; j++){a[i][j] = ns();}} return a;}

    // Math
    int max(int a, int b){return Math.max(a, b);}
    long max(long a, long b){return Math.max(a, b);}
    double max(double a, double b){return Math.max(a, b);}
    int max(int[] a){int max = a[0]; for(int value:a){max = max(max,value);} return max;}
    long max(long[] a){long max = a[0]; for(long value:a){max = max(max,value);} return max;}
    double max(double[] a){double max = a[0]; for(double value:a){max = max(max,value);} return max;}
    int min(int a, int b){return Math.min(a, b);}
    long min(long a, long b){return Math.min(a, b);}
    double min(double a, double b){return Math.min(a, b);}
    int min(int[] a){int min = a[0]; for(int value:a){min = min(min,value);} return min;}
    long min(long[] a){long min = a[0]; for(long value:a){min = min(min,value);} return min;}
    double min(double[] a){double min = a[0]; for(double value:a){min = min(min,value);} return min;}
    long sum(int[] a){long sum = 0; for(int value:a){sum += value;} return sum;}
    long sum(long[] a){long sum = 0; for(long value:a){sum += value;} return sum;}
    double sum(double[] a){double sum = 0; for(double value:a){sum += value;} return sum;}
    int gcd(int a, int b){return b == 0 ? a : gcd(b, a % b);}
    long gcd(long a, long b){return b == 0 ? a : gcd(b, a % b);}
    int lcm(int a, int b){return a / gcd(a, b) * b;}
    long lcm(long a, long b){return a / gcd(a, b) * b;}
    long fact(int n){ if(n == 0){ return 1; } long a = n; for(long i = n - 1; i >= 2; i--){ a *= i; } return a; }
    long fact(long n){ if(n == 0){ return 1; } long a = n; for(long i = n - 1; i >= 2; i--){ a *= i; } return a; }
    long ncr(int n, int r){
        long a = 1;
        for(int i = n; i > n - r; i--){
            a *= i;
        }
        long b = fact(r);
        return a / b;
    }
    long ncr(long n, long r){
        long a = 1;
        for(long i = n; i > n - r; i--){
            a *= i;
        }
        long b = fact(r);
        return a / b;
    }
    long npr(int n, int r){
        long a = 1;
        for(int i = n; i > n - r; i--){
            a *= i;
        }
        return a;
    }
    long npr(long n, long r){
        long a = 1;
        for(long i = n; i > n - r; i--){
            a *= i;
        }
        return a;
    }


    // Array
    void sort(int[] a){ Arrays.sort(a);}
    void sort(long[] a){ Arrays.sort(a);}
    void sort(double[] a){ Arrays.sort(a);}
    void sort(String[] a){ Arrays.sort(a);}
    int[] reverse(int[] a){
        int[] reversed = new int[a.length];
        for(int i = 0; i < a.length; i++){
            reversed[a.length - i - 1] = a[i];
        }
        return reversed;
    }
    long[] reverse(long[] a){
        long[] reversed = new long[a.length];
        for(int i = 0; i < a.length; i++){
            reversed[a.length - i - 1] = a[i];
        }
        return reversed;
    }
    double[] reverse(double[] a){
        double[] reversed = new double[a.length];
        for(int i = 0; i < a.length; i++){
            reversed[a.length - i - 1] = a[i];
        }
        return reversed;
    }
    char[] reverse(char[] a){
        char[] reversed = new char[a.length];
        for(int i = 0; i < a.length; i++){
            reversed[a.length - i - 1] = a[i];
        }
        return reversed;
    }
    String[] reverse(String[] a){
        String[] reversed = new String[a.length];
        for(int i = 0; i < a.length; i++){
            reversed[a.length - i - 1] = a[i];
        }
        return reversed;
    }
    boolean[] reverse(boolean[] a){
        boolean[] reversed = new boolean[a.length];
        for(int i = 0; i < a.length; i++){
            reversed[a.length - i - 1] = a[i];
        }
        return reversed;
    }
    void fill(int[] array, int x) { Arrays.fill(array, x); }
    void fill(long[] array, long x) { Arrays.fill(array, x); }
    void fill(double[] array, double x) { Arrays.fill(array, x); }
    void fill(boolean[] array, boolean x) { Arrays.fill(array, x); }
    void fill(int[][] array, int x) { for(int a[] : array) { fill(a, x); } }
    void fill(long[][] array, long x) { for(long a[] : array) { fill(a, x); } }
    void fill(double[][] array, double x) { for(double a[] : array) { fill(a, x); } }
    void fill(boolean[][] array, boolean x) { for(boolean a[] : array) { fill(a, x); } }

    // Collection
    void sort(){}
    void sortrev(){}
    // Scanner
    // StringBuilder
    // ArrayList<> nial(int n)
    // LinkedList<> nill(int n)
    // Deque<> nidq(int n)
    // PriorityQueue<> nipq(int n)
    // PriorityQueue<> nipqrev(int n) reverseOrder
    // ex) PriorityQueue<Integer> a = nipq(n);

    

    public void solve(){
        String s = ns();

        int tmp = s.length() - 1;

        while(tmp >= 0){
            if(s.lastIndexOf("dream", tmp) >= tmp - 4){
                tmp -= 5;
            } else if(s.lastIndexOf("dreamer", tmp) >= tmp - 6){
                tmp -= 7;
            } else if(s.lastIndexOf("erase", tmp) >= tmp - 4){
                tmp -= 5;
            } else if(s.lastIndexOf("eraser", tmp) >= tmp - 5){
                tmp -= 6;
            } else {
                System.out.println("NO");
                return;
            }
        }

        System.out.println("YES");
    }
    public static void main(String[] args){ new Main().solve();}
}
