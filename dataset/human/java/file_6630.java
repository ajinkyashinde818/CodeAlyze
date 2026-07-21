import java.io.*; 
import java.math.*;
import java.util.*;
public class Main {  //~IQEmperor~ 
	//All segments are like items in knapsack (either take positive or negative, that's it)
	/*Say target = 7
	 *{1,3,6,7,8} 
	 * Possible at i = 1: (1,-1)
	 * "               ": ()
	 * 
	 * */
	public static void main(String[] args) {
		FastScanner I = new FastScanner(); //Input
		OutPut O = new OutPut(); //Output
		String S = I.next();
		int N = S.length();
		int X = I.nextInt();
		int Y = I.nextInt();
		X+=8000;
		Y+=8000; //No negative out of bounds
		//(0,0) in DP will mean (-8000,-8000)
		boolean[] dpX = new boolean[16001]; //X and Y are disjoint in this question
		boolean[] dpY = new boolean[16001];
		int curdis = 0; //Current segment length
		boolean H = true;
		boolean V = false; //Are we in x-axis or y-axis
		int start = 0;
		int x = 0;
		ArrayList<Integer> hor = new ArrayList<Integer>();
		ArrayList<Integer> ver = new ArrayList<Integer>();
		for (int i = 0; i < N; i++) { //First ever segment is always positive x
			if (S.charAt(i)=='T') break;
			start++;
			x++;
		}
		for (int i = start; i < N; i++) {
			if (S.charAt(i)=='T') {
				if (H&&curdis>0) {
					hor.add(curdis);
				}else if (V&&curdis>0) {
					ver.add(curdis);
				}
				H=!H;
				V=!V; //Switching axis
				curdis = 0;
			}else curdis++;
		}
		if (H&&curdis>0) hor.add(curdis);
		else if (V&&curdis>0) ver.add(curdis);
		Collections.sort(hor);
		Collections.sort(ver);
		dpX[x+8000]=true;
		dpY[8000]=true; //Origin (y=0) is always possible
		for (int i = 0; i < hor.size(); i++) {
			int dx = hor.get(i);
			ArrayList<Integer> posX = new ArrayList<Integer>();
			for (int prev = 0; prev<=16000; prev++) {
				if (dpX[prev]) {
					dpX[prev]=false; //Have to move away now
					int pos1 = prev+dx;
					int pos2 = prev-dx;
					if (pos1<=16000) posX.add(pos1);
					if (pos2>=0) posX.add(pos2);
				}
			}
			for (int j = 0; j < posX.size(); j++) {
				int cur = posX.get(j);
				dpX[cur]=true;
			}
		}
		for (int i = 0; i < ver.size(); i++) {
			int dy = ver.get(i);
			ArrayList<Integer> posY = new ArrayList<Integer>();
			for (int prev = 0; prev<=16000; prev++) {
				if (dpY[prev]) {
					dpY[prev]=false; //Have to move away now
					int pos1 = prev+dy;
					int pos2 = prev-dy;
					if (pos1<=16000) posY.add(pos1);
					if (pos2>=0) posY.add(pos2);
				}
			}
			for (int j = 0; j < posY.size(); j++) {
				int cur = posY.get(j);
				dpY[cur]=true;
			}
		}
		O.pln(dpX[X]&&dpY[Y]?"Yes":"No"); //Already increased x and y by 8000
	}
	public static long min(long a, long b) {return Math.min(a,b);}
	public static long max(long a, long b) {return Math.max(a,b);}
	public static int min(int a, int b) {return Math.min(a,b);}
	public static int max(int a, int b) {return Math.max(a,b);}
	public static long abs(long x, long y) {return Math.abs(x-y);}
	public static long ceil(long num, long den) {long ans = num/den; if (num%den!=0) 
	ans++; return ans;}
	public static long GCD(long a, long b) {
		if (a==0||b==0) return Math.max(a,b);
		return GCD(Math.min(a, b),Math.max(a, b)%Math.min(a, b));
	}
	public static long FastExp(long base, long exp, long mod) {
		long ans=1;
		while (exp>0) {
			if (exp%2==1) ans*=base;
			exp/=2;
			base*=base;
			base%=mod;
			ans%=mod;
		}
		return ans;
	}
	public static long ModInv(long num,long mod) {return FastExp(num,mod-2,mod);}
	public static int pop(long x) { //Returns number of bits within a number
		int cnt = 0;
		while (x>0) {
			if (x%2==1) cnt++;
			x/=2;
		}
		return cnt;
	}
	static class FastScanner {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st=new StringTokenizer("");
		String next() {
			while (!st.hasMoreTokens())
				try {
					st=new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		int nextInt() {return Integer.parseInt(next());}
		long nextLong() {return Long.parseLong(next());};
		double nextDouble() {return Double.parseDouble(next());}
	}
	static class OutPut{
		PrintWriter w = new PrintWriter(System.out);
		void pln(double x) {w.println(x);w.flush();}
		void pln(boolean x) {w.println(x);w.flush();}
		void pln(int x) {w.println(x);w.flush();}
		void pln(long x) {w.println(x);w.flush();}
		void pln(String x) {w.println(x);w.flush();}
		void pln(char x) {w.println(x);w.flush();}
		void pln(StringBuilder x) {w.println(x);w.flush();}
		void pln(BigInteger x) {w.println(x);w.flush();}
		void p(int x) {w.print(x);w.flush();}
		void p(long x) {w.print(x);w.flush();}
		void p(String x) {w.print(x);w.flush();}
		void p(char x) {w.print(x);w.flush();}
		void p(StringBuilder x) {w.print(x);w.flush();}
		void p(BigInteger x) {w.print(x);w.flush();}
		void p(double x) {w.print(x);w.flush();}
		void p(boolean x) {w.print(x);w.flush();}
	}
}
