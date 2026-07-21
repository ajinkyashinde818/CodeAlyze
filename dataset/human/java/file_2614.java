import java.util.Arrays;
import java.util.Scanner;
 
class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		char[] ss = s.toCharArray();
		char[] ts = t.toCharArray();
		Arrays.sort(ss);
		Arrays.sort(ts);
		char[] rts = new char[ts.length];
		for(int i = 0;i < ts.length;i++){
			rts[i] = ts[ts.length-1-i];
		}
		String ns = new String(ss);
		String nt = new String(rts);
		if(ns.compareTo(nt)<0){
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
