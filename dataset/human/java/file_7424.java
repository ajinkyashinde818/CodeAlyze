import java.io.*;
import java.util.*;

public class Main {

	final static long MOD = 1000000007;
	public static String[] Ws = null;
	public static int wsIndx = 0;
	public static BufferedReader in = null;
	public static long cnt=0;
	public static PrintWriter pw = new PrintWriter(System.out);
	public static void main(String[] args) throws Exception {
		solution(args);
		if(in!=null){
			in.close();
		}
		pw.flush();
		pw.close();
	}

	public static void solution(String[] args) throws Exception{

		String s = nextString();
		String[] base = {"resare","remaerd","esare","maerd"};
		StringBuffer S = (new StringBuffer()).append(s).reverse();

		String ans = "NO";
		boolean flg = true;
		while(flg){
			flg=false;
			for(int i=0;i<base.length;i++){
				if(S.length()>=base[i].length()&&S.substring(0,base[i].length()).equals(base[i])){
					S.delete(0, base[i].length());
					flg=true;
					break;
				}
			}
		}
		if(S.length()==0){
			ans="YES";
		}

		pw.println(ans);

	}

	public static void dfs(int n,int cnt,ArrayList<Integer>[] tree,int parent,int[] set){
		if(n!=parent&&tree[n].size()==1){
			set[n]=cnt;
			return;
		}
		for(int x:tree[n]){
			if(x==parent){
				continue;
			}
			dfs(x,cnt+1,tree,n,set);
		}
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
