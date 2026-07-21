import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main {

	Scanner sc = new Scanner(System.in);

	int INF = 1 << 28;
	double EPS = 1e-9;

	int n;
	String s, t;
	
	void run() {
		n=sc.nextInt();
		for(int i=0;i<n;i++){
			s=sc.next();
			t=sc.next();
			solve();
		}
	}

	void solve() {
		int[] a=new int[256];
		a['m']=1000;
		a['c']=100;
		a['x']=10;
		a['i']=1;
		int v1=0;
		for(int i=0;i<s.length();i++){
			if(Character.isDigit(s.charAt(i))){
				v1+=(s.charAt(i)-'0')*a[s.charAt(i+1)];
				i++;
			}else{
				v1+=a[s.charAt(i)];
			}
		}
		int v2=0;
		for(int i=0;i<t.length();i++){
			if(Character.isDigit(t.charAt(i))){
				v2+=(t.charAt(i)-'0')*a[t.charAt(i+1)];
				i++;
			}else{
				v2+=a[t.charAt(i)];
			}
		}
		int v=v1+v2;
//		debug(v1,v2,v);
		char[] cs={'i','x','c','m'};
		String ans="";
		for(int i=0;i<4;i++){
			if(v%10==1){
				ans=cs[i]+ans;
			}else if(v%10>1){
				ans=(v%10)+""+cs[i]+ans;
			}
			v/=10;
		}
//		debug(ans);
		println(ans);
	}

	void debug(Object... os) {
		System.err.println(Arrays.deepToString(os));
	}

	void print(String s) {
		System.out.print(s);
	}

	void println(String s) {
		System.out.println(s);
	}

	public static void main(String[] args) {
		// System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		new Main().run();
	}
}
