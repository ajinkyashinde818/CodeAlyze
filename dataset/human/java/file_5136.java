// No sorceries shall prevail. //           
import java.util.*;
import java.io.*;
public class Main {
	
	static long gcd(long a, long b) { 
	      if (b == 0) 
	        return a; 
	      return gcd(b, a % b);  
	    }
	static int gcd(int a, int b) { 
	      if (b == 0) 
	        return a; 
	      return gcd(b, a % b);  
	    }
	
	static long mod = 1000000007;
	public static void main(String args[]) {
		Scanner inp=new Scanner(System.in);
		PrintWriter out=new PrintWriter(System.out);
		
		String s=inp.next();
		StringBuilder sb=new StringBuilder(s);
		int n=inp.nextInt();
		boolean reversed=false;
		char prev[]=new char[n];
		char next[]=new char[n];
		int pr=0,ne=0;
		for(int i=0;i<n;i++) {
			int x=inp.nextInt();
			if(x==1) {
				reversed= !reversed;
			}
			else {
				x=inp.nextInt();
				char k=inp.next().charAt(0);
				if(x==2 && !reversed) {
					next[ne++]=k;
				}
				else if(x==1 && reversed) {
					next[ne++]=k;
				}
				else {
					prev[pr++]=k;
				}
			}
		}
		if(!reversed) {
			for(int i=pr-1;i>=0;i--) {
				out.print(prev[i]);
			}
			for(int i=0;i<s.length();i++) {
				out.print(s.charAt(i));
			}
			for(int i=0;i<ne;i++) {
				out.print(next[i]);
			}
		}
		else {
			for(int i=ne-1;i>=0;i--) {
				out.print(next[i]);
			}
			for(int i=s.length()-1;i>=0;i--) {
				out.print(s.charAt(i));
			}
			for(int i=0;i<pr;i++) {
				out.print(prev[i]);
			}
		}
		
		out.close();
		inp.close();
	}
}
