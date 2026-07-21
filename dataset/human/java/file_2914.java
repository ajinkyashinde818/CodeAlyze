import java.io.*;
import java.util.*;

public class Main {

	final static long MOD = 1000000007;
	public static String[] Ws = null;
	public static int wsIndx = 0;
	public static BufferedReader in = null;
	public static void main(String[] args) throws Exception {
		solution(args);
		if(in!=null){
			in.close();
		}
	}

	public static void solution(String[] args) throws Exception{

		int N=nextInt();
		int M=nextInt();
		int[] a = new int[M];
		int[] b = new int[M];
		HashMap<Integer,ArrayList<Integer>> map = new HashMap<>();
		for(int i=0;i<M;i++){
			a[i]=nextInt();
			b[i]=nextInt();
			if(map.containsKey(a[i])){
				map.get(a[i]).add(b[i]);
			}else{
				ArrayList<Integer> list = new ArrayList<>();
				list.add(b[i]);
				map.put(a[i], list);
			}
		}

		if(map.containsKey(1)){
			for(int key:map.get(1))
				if(map.containsKey(key)){
					for(int key2:map.get(key)){
						if(key2==N){
							System.out.println("POSSIBLE");
							return;
						}
					}
				}
		}
		System.out.println("IMPOSSIBLE");


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
