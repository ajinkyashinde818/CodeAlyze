import java.io.*;
import java.util.*;

public class Main {

	final static long MOD = 1000000007;
	public static String[] Ws = null;
	public static int wsIndx = 0;
	public static BufferedReader in = null;
	public static void main(String[] args) throws Exception {

		int N =nextInt();
		long K = nextLong();
		int[] A = nextInts();

		int[] to = new int[N+1];
		to[0]=1;
		HashMap<Integer,Integer> map = new HashMap<>();
		map.put(1, 0);
		int loopCnt=0;
		int tail = 0;
		for(int i=1;i<=N;i++){
			to[i]=A[to[i-1]-1];
			if(map.containsKey(A[to[i-1]-1])){
				loopCnt=i-map.get(A[to[i-1]-1]);
				tail=i-loopCnt+1;
				break;
			}
			map.put(A[to[i-1]-1], i);
		}
		int idx ;
		if(K<=tail){
			idx=(int)K;
		}else{
			idx=(int)((K-tail)%loopCnt)+tail;
		}
		System.out.println(to[idx]);
	}


	public static String[] toStringArray(String s) {
		String[] tmp = new String[s.length()];
		char[] c = s.toCharArray();
		for (int i = 0; i < tmp.length; i++) {
			tmp[i] = String.valueOf(c[i]);
		}
		return tmp;
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
