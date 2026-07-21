import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.*;
import java.math.*;
public class Main {
	public static int gcd(int a,int b) {
		while(true) {
			a%=b;
			if(a==0)return b;
			b%=a;
			if(b==0)return a;
		}
	}
	public static void main(String[] args) throws IOException{
		BufferedReader re=new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer t=new StringTokenizer(re.readLine());
		int a=Integer.parseInt(t.nextToken()),b=Integer.parseInt(t.nextToken()),k=Integer.parseInt(t.nextToken());
		int c=gcd(a,b),d=c;
		while(k>1) {
			if(c%--d==0)--k;
		}
		System.out.println(d);
	}
}
