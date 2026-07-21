import java.io.*;
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
		solutionA(args);
		if(in!=null){
			in.close();
		}
		pw.flush();
		pw.close();
	}

	public static void solutionA(String[] args) throws Exception{

		int N = nextInt();
		int M = nextInt();
		char[][] A  = new char[N][N];
		char[][] B  = new char[M][M];
		for(int i=0;i<N;i++) {
			A[i]=nextString().toCharArray();
		}
		for(int i=0;i<M;i++) {
			B[i]=nextString().toCharArray();
		}

		for(int ny=0;ny<=N-M;ny++) {
			for(int nx=0;nx<=N-M;nx++) {
				boolean flg = true;

				for(int y=0;y<M;y++) {
					for(int x=0;x<M;x++) {
						if(A[ny+y][nx+x]!=B[y][x]) {
							flg=false;
							break;
						}
					}
					if(!flg) {
						break;
					}
				}
				if(flg) {
					pw.println("Yes");
					return;
				}
			}
		}
		pw.println("No");
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
