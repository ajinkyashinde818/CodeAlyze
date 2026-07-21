import java.io.*;
import java.math.*;
import java.util.*;
public class Main{ 
 
	public static void main(String[] args) { //Partition babyyyyyyyyy
		FastScanner I = new FastScanner(); //Input
		OutPut O = new OutPut(); //Output
		String s = I.next();
		String t = I.next();
		ArrayList<Character> inc = new ArrayList<Character>();
		PriorityQueue<Character> dec = new PriorityQueue<Character>(Collections.reverseOrder());
		for (int i = 0; i < s.length(); i++) inc.add(s.charAt(i));
		for (int i = 0; i < t.length(); i++) dec.add(t.charAt(i));
		ArrayList<Character> inv = new ArrayList<Character>();
		while (!dec.isEmpty()) inv.add(dec.poll());
		Collections.sort(inc);
		boolean ez=false;
		boolean pos = false;
		for (int i = 0; i<Math.min(inv.size(),inc.size()); i++) {
			if (inc.get(i)<inv.get(i)) {
				ez=true;
				pos=true;
				break;
			}else if (inc.get(i)>inv.get(i)) {
				ez=true;
				pos=false;
				break;
			}
		}
		if (!ez) { //Equal prefix case
			if (s.length()<t.length()) pos=true; //If same prefix but shorter length 
			//(i.e abc and abcaaaaaa, abc is lexicographically smaller (similar 
			//to base 10 numbers; Earlier digits/letters hold greater value, but if same,
			//number of digits determines which is larger
		}
		O.pln(pos?"Yes":"No");
	}
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
	}
	static class OutPut{
		PrintWriter w = new PrintWriter(System.out);
		void pln(int x) {w.println(x);w.flush();}
		void pln(long x) {w.println(x);w.flush();}
		void pln(String x) {w.println(x);w.flush();}
		void pln(char x) {w.println(x);w.flush();}
		void pln(StringBuilder x) {w.println(x);w.flush();}
		void p(int x) {w.print(x);w.flush();}
		void p(long x) {w.print(x);w.flush();}
		void p(String x) {w.print(x);w.flush();}
		void p(char x) {w.print(x);w.flush();}
		void p(StringBuilder x) {w.print(x);w.flush();}
	}
}
