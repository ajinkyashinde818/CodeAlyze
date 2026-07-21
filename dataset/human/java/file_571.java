import java.io.*;
import java.util.*;

class Main{

    void solve(){
        int n = ni();
        int r = ni();

        System.out.println(n >= 10 ? r : r + 100 * (10 - n));

    }

    public static void main(String[] args){
        new Main().solve();
    }

    private FastScanner scan = new FastScanner();
    private final int MOD = 1_000_000_007;
    private final int INF = 2147483647;
    private final long LINF = 9223372036854775807L;
    private long[] fac;
    private long[] finv;
    private long[] inv;

    // Scanner
    int ni(){ return scan.nextInt();}
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

    // Mathmatics
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
    // nPr(int)
    long npr(int n, int r){
        long a = 1;
        for(int i = n; i > n - r; i--){
            a *= i;
        }
        return a;
    }
    // nPr(long)
    long npr(long n, long r){
        long a = 1;
        for(long i = n; i > n - r; i--){
            a *= i;
        }
        return a;
    }
    // 素数判定(int)
    boolean checkPrime(int n){
        for(int i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    // 素数判定(long)
    boolean checkPrime(long n){
        for(long i = 2; i * i <= n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    // mod pにおける累乗 a^n
    long modpow(long a, long n, long p){
        long res = 1;
        while(n > 0){
            if((n & 1) == 1){
                res = res * a % p;
            }
            a = a * a % p;
            n = n >> 1;
        }
        return res;
    }
    // mod pにおけるaの逆元a^-1
    long modinv(long a, long p){
        return modpow(a, p - 2, p);
    }
    // fac,finv,invの初期化
    void comInit(int max){
        fac = new long[max];
        finv = new long[max];
        inv = new long[max];
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for(int i = 2; i < max; i++){
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    // 二項係数nCr
    long com(int n, int r){
        if(n < r || (n < 0 || r < 0)){
            return 0;
        }
        return fac[n] * (finv[r] * finv[n - r] % MOD) % MOD;
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

    // Algorithm
    // ソート済みint型配列でkey以上の値の最小indexを返す
    int lowerBound(int[] a, int key){
        int ng = -1;
        int ok = a.length;
        while(Math.abs(ok - ng) > 1){
            int mid = (ok + ng) / 2; 
            if(a[mid] >= key){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
    // ソート済みlong型配列でkey以上の値の最小indexを返す
    int lowerBound(long[] a, long key){
        int ng = -1;
        int ok = a.length;
        while(Math.abs(ok - ng) > 1){
            int mid = (ok + ng) / 2; 
            if(a[mid] >= key){
                ok = mid;
            } else {
                ng = mid;
            }
        }
        return ok;
    }
    // 文字列sとtの最長共通部分列の長さを返す
    int lcs(String s , String t){
        int[][] dp = new int[s.length() + 1][t.length() + 1];

        for(int i = 0; i < s.length(); i++){
            for(int j = 0; j < t.length(); j++){
                if(s.charAt(i) == t.charAt(j)){
                    dp[i + 1][j + 1] = max(dp[i][j] + 1, dp[i + 1][j + 1]);
                }
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
                dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
            }
        }

        return dp[s.length()][t.length()];
    }

}

// 順列を管理する
class Permutation {
    private int number;
    private int listSize;
    private int searched;
    private int nextIndex;
    private int[][] permList;

    Permutation(int num) {
        this.number = num;
        this.listSize  = this.fact(this.number);
        this.searched   = 0;
        this.nextIndex = 0;
        this.permList  = new int[this.listSize][this.number];

        this.create(0, new int[this.number], new boolean[this.number]);
    }

    int[] nextPerm() {
        return permList[this.nextIndex++];
    }

    boolean isNext() {
        if(this.nextIndex < this.listSize) {
            return true;
        } else {
            this.nextIndex = 0;
            return false;
        }
    }

    int fact(int n){
        return n == 0 ? 1 : n * fact(n-1);
    }

    void create(int num, int[] list, boolean[] flag) {
        if(num == this.number) {
            copyArray(list, permList[this.searched]);
            this.searched++;
        }
        for(int i = 0; i < this.number; i++){
            if(flag[i]) continue;
            list[num] = i;
            flag[i] = true;
            this.create(num+1, list, flag);
            flag[i] = false;

        }
    }

    void copyArray(int[] from, int[] to) {
        for(int i=0; i<from.length; i++) to[i] = from[i];
    }

    void printNum(int[] nums) {
        for(int n : nums) System.out.print(n);
        System.out.println();
    }
}

// 標準のScannerより高速に標準入力する
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
