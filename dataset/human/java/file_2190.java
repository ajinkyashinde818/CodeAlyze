import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;


public class Main {

	final static long MOD = 1000000007;
	public static String[] Ws = null;
	public static int wsIndx = 0;
	public static BufferedReader in = null;
	public static long cnt=0;
	public static PrintWriter pw = new PrintWriter(System.out);
	public static void main(String[] args) throws Exception {
		solutionD(args);
		if(in!=null){
			in.close();
		}
		pw.flush();
		pw.close();
	}

	public static void solutionA(String[] args) throws Exception{

		pw.println(nextInt()*nextInt());
	}
	public static void solutionB(String[] args) throws Exception{
		int N = nextInt();
		long[] a = nextLongs();
		Arrays.sort(a);
		long ans = a[0];
		for(int i=1;i<N;i++) {
			long x = 0;
			try{
				x= Math.multiplyExact(ans, a[i]);
			}catch(Exception e) {
				pw.println(-1);
				return;
			}
			if(x>=1000000000000000001L) {
				pw.println(-1);
				return;
			}
			ans=x;
		}
		pw.println(ans);
	}
	public static void solutionC(String[] args) throws Exception{
		String A = nextString();
		String B = nextString();
		BigDecimal bA = new BigDecimal(A);
		BigDecimal bB = new BigDecimal(B);

		pw.println(bA.multiply(bB).longValue());
	}
	public static void solutionD(String[] args) throws Exception{
		long N=nextLong();
		TreeMap<Long,Long> map = primeFactorize(N);

		long ans = 0;
		long val;
		for(long key:map.keySet()) {
			if(key==1)
				continue;
			val=map.get(key);
			long n = 0;
			while(val>=n) {
				n++;
				val-=n;
				if(val<0) {
					n--;
					break;
				}
			}
			ans+=n;
		}
		pw.println(ans);
	}


	public static TreeMap<Long, Long> primeFactorize(long N) {
		TreeMap<Long, Long> map = new TreeMap<>();
		for (long i = 2; i * i <= N; i++) {
			long k = 0;
			while (N % i == 0) {
				k++;
				N /= i;
			}
			map.put(i, k);
		}
		map.put(N, 1L);
		return map;
	}

	public static void check() throws Exception{
		if(in == null){
			in = new BufferedReader(new InputStreamReader(System.in));
		}
		if(Ws==null || Ws.length<=wsIndx){
			Ws = in.readLine().split(" ");
			wsIndx=0;
		}
	}
	public static int nextInt()throws Exception{
		check();
		return Integer.parseInt(Ws[wsIndx++]);
	}

	public static long nextLong()throws Exception{
		check();
		return Long.parseLong(Ws[wsIndx++]);
	}

	public static String nextString()throws Exception{
		check();
		return Ws[wsIndx++];
	}

	public static int[] nextInts()throws Exception{
		check();
		int[] tmp = new int[Ws.length];
		for(int i=0;i<tmp.length;i++){
			tmp[i]=Integer.parseInt(Ws[i]);
		}
		wsIndx=Ws.length;
		return tmp;
	}

	public static long[] nextLongs()throws Exception{
		check();
		long[] tmp = new long[Ws.length];
		for(int i=0;i<tmp.length;i++){
			tmp[i]=Long.parseLong(Ws[i]);
		}
		wsIndx=Ws.length;
		return tmp;
	}

	public static String[] nextStrings()throws Exception{
		check();
		wsIndx=Ws.length;
		return Ws;
	}

}
