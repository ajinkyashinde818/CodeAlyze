import java.io.*;
import java.util.*;

public class Main {

	final static long MOD = 1000000007;
	public static String[] Ws = null;
	public static int wsIndx = 0;
	public static BufferedReader in = null;
	public static void main(String[] args) throws Exception {

		int N =nextInt();
		int M =nextInt();
		int X =nextInt();
		long[] C = new long[N];
		long[][] A  = new long[N][M];
		for(int i=0;i<N;i++){
			C[i]=nextLong();
			for(int k=0;k<M;k++){
				A[i][k]=nextLong();
			}
		}
		long ans =Long.MAX_VALUE;
		for(int i=1;i<(1<<N);i++){
			int[] p = new int[N];

			for(int k=0;k<N;k++){
				p[k]=(i>>k)&1;
			}
			long[] s = new long[M];
			Arrays.fill(s, 0);
			long cnt = 0;
			for(int k=0;k<N;k++){
				if(p[k]==0){
					continue;
				}
				cnt+=C[k];
				for(int m=0;m<M;m++){
					s[m]+=A[k][m];
				}
			}
			boolean flg=true;
			for(int k=0;k<M;k++){
				if(s[k]<X){
					flg=false;
					break;
				}
			}
			if(flg){
				ans=Math.min(ans, cnt);
			}
		}

		if(ans==Long.MAX_VALUE){
			ans=-1;
		}
		System.out.println(ans);
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
