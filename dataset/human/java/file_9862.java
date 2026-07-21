import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.NoSuchElementException;
import java.util.Queue;

class Main implements Runnable {
	private final FastScanner sc;
	private final PrintWriter out;
	//private final long MOD = 1000000007;
	//private final int[] d8x = {-1,0,1,1,1,0,-1,-1};
	//private final int[] d8y = {-1,-1,-1,0,1,1,1,0};
	//private final int[] d4x = {0,1,0,-1};
	//private final int[] d4y = {-1,0,1,0};
	int n,m,x;
	int[] c;
	int[][] a;
	
	public static void main(String[] args) {
		new Thread(null, new Main(), "", 16L * 1024 * 1024).start();
	}

	Main() {
		sc = new FastScanner();
		out = new PrintWriter(System.out);
	}

	private void init() throws Exception {
		n = sc.nextInt();
		m = sc.nextInt();
		x = sc.nextInt();
		c = new int[n];
		a = new int[n][m];
		for(int i=0;i<n;i++){
			c[i] = sc.nextInt();
			for(int j=0;j<m;j++){
				a[i][j] = sc.nextInt();
			}
		}
	}

	private void solve() throws Exception{
		int min = Integer.MAX_VALUE;
		Queue<Data> q = new ArrayDeque<Data>();
		q.offer(new Data(0,0,m));
		while(q.size()>0){
			Data d = q.poll();
			if(d.isMastered(x)) min = Math.min(min, d.getSum());
			if(d.getIndex()<n){
				q.add(d.make(d.getIndex()+1, d.getSum()+c[d.getIndex()],a[d.getIndex()]));
				q.add(d.make(d.getIndex()+1, d.getSum()));
			}
		}
		out.println(min==Integer.MAX_VALUE?-1:min);
	}

	public void run() {
		try {
			init();
			sc.close();
			solve();
		} catch (Exception e) {
			e.printStackTrace();
			System.exit(1);
		}
		out.flush();
		out.close();
	}
}

class Data {
	private int index;
	private int sum;
	private int[] skills;
	
	public Data(int index,int sum,int x){
		this.index = index;
		this.sum = sum;
		this.skills = new int[x];
	}
	public Data make(int index,int sum,int[] c){
		return new Data(index,sum,skills.length,skills,c);
	}
	public Data make(int index,int sum){
		return new Data(index,sum,skills.length,skills);
	}
	private Data(int index,int sum,int m,int[] skills){
		this(index, sum, m);
		for(int i=0;i<m;i++){
			this.skills[i] = skills[i];
		}
	}
	private Data(int index,int sum,int m,int[] skills,int[] a){
		this(index,sum,m);
		for(int i=0;i<m;i++){
			this.skills[i] = skills[i] + a[i];
		}
	}
	public int getIndex() {
		return index;
	}
	public int getSum() {
		return sum;
	}
	public boolean isMastered(int x){
		for(int i=0;i<skills.length;i++){
			if(skills[i]<x){
				return false;
			}
		}
		return true;
	}
}

class MyMath{
	public static int floor(double a){
		BigDecimal ans = new BigDecimal(String.format("%.6f", a));
		return ans.setScale(0, RoundingMode.FLOOR).intValue();
	}
	public static int ceil(double a){
		BigDecimal ans = new BigDecimal(String.format("%.6f", a));
		return ans.setScale(0, RoundingMode.CEILING).intValue();
	}
	public static double NthRoot(double num,double n){
		return Math.pow(Math.E, Math.log(num)/n);
	}
	public static long gcd(long a,long b){
		if(a<b) return gcd(b,a);
		if(b==0) return a;
		return gcd(b,a%b);
	}
	public static long gcd(long... num){
		if(num.length<2) throw new IllegalArgumentException();
		if(num.length == 2) return gcd(num[0],num[1]);
		num[num.length-2] = gcd(num[num.length-2]);
		return gcd(Arrays.copyOfRange(num,0,num.length-1));
	}
}

class ExIntVector {
	private int[] a;
	private int cnt;
	public ExIntVector(int max){
		a = new int[max];
		cnt = 0;
	}
	public int size(){
		return cnt;
	}
	public void add(int x){
		a[cnt++] = x;
	}
	public int get(int i){
		return a[i];
	}
	public int getLast(){
		return a[cnt-1];
	}
	public int[] toArray(){
		return a;
	}
}

class FastScanner {
	private final InputStream in = System.in;
	private final byte[] buffer = new byte[1024];
	private int ptr = 0;
	private int buflen = 0;

	private boolean read() {
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
			return true;
		}
	}

	private boolean hasNext() {
		while (read() && !isVisibleChar(buffer[ptr]))
			ptr++;
		return read();
	}

	private int getNextChar() {
		if (read()) {
			ptr++;
			return buffer[ptr - 1];
		} else {
			return -1;
		}
	}

	private static boolean isVisibleChar(int code) {
		return code >= 33 && code <= 126;
	}

	public String next() {
		if (!hasNext())
			throw new NoSuchElementException();
		StringBuilder sb = new StringBuilder();
		int b = getNextChar();
		while (isVisibleChar(b)) {
			sb.appendCodePoint(b);
			b = getNextChar();
		}
		return sb.toString();
	}

	public long nextLong() {
		if (!hasNext())
			throw new NoSuchElementException();
		long n = 0;
		boolean sign = true;
		int b = getNextChar();
		if (b == '-') {
			sign = false;
			b = getNextChar();
		}
		if (b < '0' || b > '9') {
			throw new NumberFormatException();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				n *= 10;
				n += b - '0';
			} else if (b == -1 || !isVisibleChar(b)) {
				return sign ? n : -n;
			} else {
				throw new NumberFormatException();
			}
			b = getNextChar();
		}
	}

	public int nextInt() {
		long n = nextLong();
		if (n < Integer.MIN_VALUE || n > Integer.MAX_VALUE)
			throw new NumberFormatException();
		return (int) n;
	}

	public double nextDouble() {
		return Double.parseDouble(next());
	}
	
	public char nextChar() {
		if (!hasNext())
			throw new NoSuchElementException();
		int b = getNextChar();
		while (!isVisibleChar(b)) {
			b = getNextChar();
		}
		return (char) b;
	}

	public void close() {
		try {
			in.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}

class IntQueue {
	protected int[] a;
	protected int head, tail;

	public IntQueue(int max) {
		a = new int[max];
	}

	public void offer(int x) {
		a[tail++] = x;
	}

	public int poll() {
		return a[head++];
	}

	public int peek() {
		return a[head];
	}
	
	public int size() {
		return tail - head;
	}
}
