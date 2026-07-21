import java.util.*;

import static java.lang.System.*;

class Main {
	public static Scanner sc = new Scanner(in);
	public static Random rand=new Random();

	public int decodeMCXI(String str){
		int val=0;
		int pre=1;
		for(int i=0;i<str.length();i++){
			switch(str.charAt(i)){
			case 'm':
				val+=pre*1000;
				pre=1;
				break;
			case 'c':
				val+=pre*100;
				pre=1;
				break;
			case 'x':
				val+=pre*10;
				pre=1;
				break;
			case 'i':
				val+=pre;
				pre=1;
				break;
			default:
				pre=str.charAt(i)-'0';
				break;
			}
		}
		return val;
	}

	public String encodeMCXI(int val){
		StringBuilder sb=new StringBuilder();
		int m=val/1000;
		if(m>=2)sb.append(m);
		if(m>=1)sb.append("m");
		val%=1000;

		int c=val/100;
		if(c>=2)sb.append(c);
		if(c>=1)sb.append("c");
		val%=100;

		int x=val/10;
		if(x>=2)sb.append(x);
		if(x>=1)sb.append("x");
		val%=10;


		int i=val;
		if(i>=2)sb.append(i);
		if(i>=1)sb.append("i");

		return sb.toString();
	}

	public void run() {
		int n=sc.nextInt();
		for(int i=0;i<n;i++){
			int l=decodeMCXI(sc.next()),r=decodeMCXI(sc.next());
			ln(encodeMCXI(l+r));
		}
	}
	public static void main(String[] args) {
		new Main().run();
	}

	public int[] nextIntArray(int n){
		int[] res=new int[n];
		for(int i=0;i<n;i++){
			res[i]=sc.nextInt();
		}
		return res;
	}
	public static void pr(Object o) {
		out.print(o);
	}
	public static void ln(Object o) {
		out.println(o);
	}
	public static void ln() {
		out.println();
	}
}
