import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.List;
import java.util.NoSuchElementException;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) throws IOException {
        new Main().solve();
    }

    private void solve() throws IOException {
        try {
            //			solveA();
            //			solveB();
            //			solveC();
//			solveD();
//            solveE();
            solveEEditorial();
            //			 solveF();
        } finally {
            if (in != null) {
                in.close();
            }
            if (out != null) {
                out.flush();
                out.close();
            }
        }

    }

    private void solveA() {
        int a = nextInt();
        int b = nextInt();
        out.println(6 - a - b);
    }

    private void solveB() {
        int n = nextInt();
        char[] s = next().toCharArray();
        char[] t = next().toCharArray();
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < t.length; i++) {
            builder.append(s[i]).append(t[i]);
        }

        out.println(builder.toString());
    }

    private void solveC() {
        long a = nextLong();
        long b = nextLong();

        out.println(getLcm(a, b));
    }

    private long getLcm(long a, long b) {
        return (a * b) / getGcd(a, b);
    }

    private long getGcd(long a, long b) {
        long max = Math.max(a, b);
        long min = Math.min(a, b);
        long amari = max % min;
        while (amari != 0) {
            max = min;
            min = amari;
            amari = max % min;
        }
        return min;
    }

    private void solveD() {
        int n = nextInt();
        int[] a = IntStream.range(0, n).map(i -> nextInt()).toArray();
        int cnt = 0;
        int num = 1;
        for (int i = 0; i < a.length; i++) {
            if (a[i] == num) {
                num++;
            } else if (a[i] != num) {
                cnt++;
            }
        }
        out.println(cnt == n ? -1 : cnt);
    }

    /**
     * 1333! の末尾に 0 が何個つくか？
     * <p>
     * という感じの問題は、中学受験でも高校受験でも大学受験でもよく見る問題ではある。具体的な解法も割と明快で、1333! を
     * <p>
     * 1333!=2a×5b×…と素因数分解したときに、c=min(a,b) 個の分だけ「2 と 5 のペアを作って 10 を作る」ことができる。よって、 1333! の末尾には c 個の 0 がつくことになる。
     * <p>
     * そして、割と明らかに a≥b となっていることがわかる。よって b を求めればよい。b を求めるには、以下のように考えればよい。
     * <p>
     * 1,2,3,…,1333 のうち、5 で 1 回以上割れる数は、5,10,15,… の 1333 / 5 = 266 個
     * 1,2,3,…,1333 のうち、5 で 2 回以上割れる数は、25,50,75,… の 1333 / 25 = 53 個
     * 1,2,3,…,1333 のうち、5 で 3 回以上割れる数は、125,250,375,… の 1333 / 125 = 10 個
     * 1,2,3,…,1333 のうち、5 で 4 回以上割れる数は、625,1250 の 1333 / 625 = 2 個
     * <p>
     * これらを合計して、266 + 53 + 10 + 2 = 331 個となる。
     * <p>
     * N が偶数のとき
     * たとえば N=10 のとき
     * <p>
     * 10×8×6×4×2=25(5×4×3×2×1)=24(5!)
     * となる。つまり、結局、(N2)! の末尾に 10 が何個あるかを求める問題に帰着された。
     */
    private void solveE() {
        long n = nextLong();
        if (n < 10 || n % 2 != 0) {
            out.println(0);
            return;
        }

        /*
        2 * f(2-2){f(0)}
        3 * f(3-2){f(1)}
         */
        long wk = n / 2;
        long res = 0;
        while (wk != 0) {
            res += wk / 5;
            wk /= 5;
        }
        out.println(res);
    }

    private void solveEEditorial() {
        long n = nextLong();
		if (n < 10 || n % 2 != 0) {
			out.println(0);
			return;
		}
        out.println(Math.min(g2(n, 2), g2(n, 5)));
    }

    private long g2(long n, long p) {
        if (n % 2 == 1) {
            return g1(n, p) - g2(n, p);
        } else {
            long res = g1(n / 2, p);
            if (p == 2)
                res += n / 2;
            return res;
        }
    }

    private long g1(long n, long p) {
        if (n == 0)
            return 0;
        return n / p + g1(n / p, p);
    }

    private void solveF() {
        int n = nextInt();

        out.println("");
    }

    /*
     * 階乗計算の最大値
     * もっと大きいのが必要ならここを修正
     */
    private final int FACTORIAL_NUM = 111111;
    /*
     * 階乗の事前計算（mod 済）
     */
    private long[] factorial = new long[FACTORIAL_NUM];
    /*
     * 逆数の事前計算（mod 済）
     */
    private long[] reverseFactorial = new long[FACTORIAL_NUM];
    private boolean isInitFactorial = false;

    /**
     * 階乗計算の事前累積和
     * [1, 1, 2, 3, 4, 5, … FACTORIAL_NUM]
     * mod済
     */
    private void initFactorial(long mod) {
        factorial[0] = 1;
        for (int i = 1; i < FACTORIAL_NUM; i++) {
            factorial[i] = (factorial[i - 1] * i) % mod;
        }
    }

    /**
     * 逆数の事前計算
     * もっと速い方法があったので修正
     */
    private void initReverseFactorial(long mod) {

        reverseFactorial[FACTORIAL_NUM - 1] = modInverse(factorial[FACTORIAL_NUM - 1], mod);
        for (int i = FACTORIAL_NUM - 2; i >= 0; i++) {
            /*
             * 以下を利用する。
             * これにより毎回modInverseしなくてよくなる
             * (N!)^(-1) * N -> ((N - 1)!)^(-1)
             * (N-1!)^(-1) * N -> ((N - 2)!)^(-1)
             */
            reverseFactorial[i] = (reverseFactorial[i + 1] * (i + 1)) % mod;
        }
        //		reverseFactorial[0] = 1;
        //		for (int i = 0; i < FACTORIAL_NUM; i++) {
        //			reverseFactorial[i] = modInverse(factorial[i], mod);
        //		}
    }

    /**
     * フェルマーの小定理を用いて逆元を求める。
     * ある数xのmod p（pは素数）の逆数x'はx' = x^(p-2)
     * 繰り返し二乗法を用いて計算する。
     * http://satanic0258.hatenablog.com/entry/2016/04/29/004730
     * {@link BigInteger#modInverse(BigInteger)}とどちらが速いか？
     *
     * @param x
     * @return
     */
    private long modInverse(long x, long mod) {
        long res = 1L;
        long k = mod - 2L;
        long y = x;
        while (k != 0) {
            if (k % 2 != 0) {
                res = (res * y) % mod;
            }
            y = (y * y) % mod;
            k /= 2;
        }
        return res;
    }

    private void initFactorialCalc(long mod) {
        if (isInitFactorial) {
            //初期化済みならreturn
            return;
        }
        //階乗の事前計算
        initFactorial(mod);
        //逆数の計算もしておく
        initReverseFactorial(mod);
        isInitFactorial = true;
    }

    /**
     * 組み合わせ
     * nCk -> n! / k!・(n-k)!
     *
     * @param n
     * @param k
     * @param mod
     * @return
     */
    private long combination(int n, int k, long mod) {
        initFactorialCalc(mod);
        if (k < 0 || n < k) {
            return 0;
        }

        //分子の計算
        long calResN = factorial[n];

        //分母の計算
        long calResNK = reverseFactorial[n - k];
        long calcResK = reverseFactorial[k];
        long denominator = (calResNK * calcResK) % mod;

        return (calResN * denominator) % mod;

    }

    /**
     * 順列
     * nPk -> n! / (n-k)!
     *
     * @param n
     * @param k
     * @return
     */
    private long permutation(int n, int k, long mod) {
        initFactorialCalc(mod);
        if (k < 0 || n < k) {
            return 0;
        }
        long calResN = factorial[n];
        long calResNK = reverseFactorial[n - k];
        return (calResN * calResNK) % mod;
    }

    /**
     * 多項係数
     * 文字aをp個,bをq個,cをr個, dをs個 あわせてn個を1列に並べるときの並べ方
     * n! / p!・q!・r!・s!
     *
     * @param n
     * @param strNum
     * @param mod
     * @return
     */
    private long multinominalCoefficient(int n, List<Integer> strNum, int mod) {
        initFactorialCalc(mod);

        long calResN = factorial[n];
        long calResDenomi = 1;
        for (Integer num : strNum) {
            calResDenomi *= reverseFactorial[num];
        }
        return (calResN * calResDenomi) % mod;
    }

    /**
     * 重複組合せ nHr （同次積）
     * nHr = (n+r-1)Cr
     * 異なるn個のものから重複を許してr個取る組合せの総数
     * 例：
     * リンゴ，ミカン，牛肉の3種類の果物があります．これらの中から6個の食材を買って帰ります．
     * このとき，何通りの買い方がありますか？ただし，含まれない食材があってもよいものとします
     *
     * @param n
     * @param r
     * @param mod
     * @return
     */
    private long homogeneousProduct(int n, int r, long mod) {
        if (n == 0 && r == 0) {
            return 1;
        }
        return combination(n + r - 1, r, mod);
    }

    private final PrintWriter out = new PrintWriter(System.out);
    private final InputStream in = System.in;
    private final byte[] buffer = new byte[1024];
    private int ptr = 0;
    private int buflen = 0;

    private boolean hasNextByte() {
        if (ptr < buflen) {
            return true;
        } else {
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

    private int readByte() {
        if (hasNextByte())
            return buffer[ptr++];
        else
            return -1;
    }

    private static boolean isPrintableChar(int c) {
        return 33 <= c && c <= 126;
    }

    private void skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr]))
            ptr++;
    }

    public boolean hasNext() {
        skipUnprintable();
        return hasNextByte();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public String next() {
        if (!hasNext())
            throw new NoSuchElementException();
        StringBuilder sb = new StringBuilder();
        int b = readByte();
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public long nextLong() {
        if (!hasNext())
            throw new NoSuchElementException();
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
        while (true) {
            if ('0' <= b && b <= '9') {
                n *= 10;
                n += b - '0';
            } else if (b == -1 || !isPrintableChar(b)) {
                return minus ? -n : n;
            } else {
                throw new NumberFormatException();
            }
            b = readByte();
        }
    }
}
