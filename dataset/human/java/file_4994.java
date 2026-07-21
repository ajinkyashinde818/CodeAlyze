import java.io.*;
import java.util.*;

public class Main {

	final static long MOD = 1000000007L;
	public static String[] Ws = null;
	public static int wsIndx = 0;
	public static BufferedReader in = null;
	public static ArrayList<int[]> list = new ArrayList<>();
	public static void main(String[] args) throws Exception {


		String S = nextString();
		int revFlg=-1;
		int Q = nextInt();
		int T=0 ;
		int F=0;
		String C="";

		ArrayDeque<String> q = new ArrayDeque<>(Q+S.length());
		String[] s = toStringArray(S);
		for(int i=0;i<s.length;i++){
			q.add(s[i]);
		}
		for(int i=0;i<Q;i++){
			T=nextInt();
			if(T==2){
				F=nextInt();
				C=nextString();
			}
			if(T==1){
				revFlg*=-1;
			}else{
				if(F==1){
					if(revFlg==-1){
						q.addFirst(C);
					}else{
						q.add(C);
					}
				}else{
					if(revFlg==-1){
						q.add(C);
					}else{
						q.addFirst(C);
					}
				}
			}
			//System.out.println(i);
		}
		StringBuffer b = new StringBuffer(q.size()) ;
		if(revFlg==-1){
			while(!q.isEmpty()){
				b.append(q.poll());
			}
		}else{
			while(!q.isEmpty()){
				b.append(q.pollLast());
			}
		}


		System.out.println(b.toString());
	}



	public static String[] toStringArray(String s) {
		String[] tmp = new String[s.length()];
		char[] c = s.toCharArray();
		for (int i = 0; i < tmp.length; i++) {
			tmp[i] = String.valueOf(c[i]);
		}
		return tmp;
	}

	public static String concatStringArray(String[] s){
		StringBuffer sb = new StringBuffer();
		for(String x:s){
			sb.append(x);
		}
		return sb.toString();
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
