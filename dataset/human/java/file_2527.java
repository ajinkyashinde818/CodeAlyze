import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		String a=sc.next(),b=sc.next();
		char[] x=new char[a.length()];
		char[] y=new char[b.length()];
		char[] t=new char[b.length()];
		for(int i=0;i<a.length();i++){
			x[i]=a.charAt(i);
		}
		for(int i=0;i<b.length();i++){
			y[i]=b.charAt(i);
		}
		Arrays.sort(x);
		Arrays.sort(y);
		for(int i=0;i<b.length();i++){
			t[i]=y[b.length()-1-i];
		}
		String h="",j="";
		for(char p:x)
			h+=p;
		for(char p:t)
			j+=p;
		String[] r={h,j};
		String[] e={h,j};
		Arrays.sort(r);
		if(a.equals(b))
			System.out.print("No");
		else if(r[0].equals(e[0]))
			System.out.print("Yes");
		else
			System.out.print("No");
			
	}
}
