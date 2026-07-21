import java.util.*;
import java.lang.*;
import java.math.*;
import java.io.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class Main{

	Scanner sc=new Scanner(System.in);

	int INF=1<<28;
	double EPS=1e-9;

	int m, n;
	int[] a;

	void run(){
		for(;;){
			m=sc.nextInt();
			n=sc.nextInt();
			if((m|n)==0){
				break;
			}
			a=new int[n];
			for(int i=0; i<n; i++){
				a[i]=sc.nextInt();
			}
			solve();
		}
	}

	void solve(){
		int left=0, right=1500000;
		for(int i=0; i<100; i++){
			int mid=(left+right)/2;
			if(check(mid)){
				right=mid;
			}else{
				left=mid;
			}
		}
		println(""+right);
	}

	boolean check(int b){
		int d=1;
		int sum=0;
		for(int i=0; i<n; i++){
			if(a[i]>b){
				return false;
			}
			sum+=a[i];
			if(sum>b){
				sum=a[i];
				d++;
			}
		}
		return d<=m;
	}

	void debug(Object... os){
		System.err.println(Arrays.deepToString(os));
	}

	void print(String s){
		System.out.print(s);
	}

	void println(String s){
		System.out.println(s);
	}

	public static void main(String[] args){
		// System.setOut(new PrintStream(new BufferedOutputStream(System.out)));
		new Main().run();
	}
}
