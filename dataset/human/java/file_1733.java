import java.util.Scanner;

public class Main {

	static Scanner scanner;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    long N=gi();
	    String S= gs();
	    long[] K=new long[26];
	    for(int i=0;i<N;i++) {
	    	char c=S.charAt(i);
	    	K[c-97]++;
	    }
	    long a=1;
	    for(int i=0;i<K.length;i++) {
	    	if(K[i]==0) continue;
	    	a*=K[i]+1;
	    	a=a%1000000007;
	    }
	    a=(a+1000000006)%1000000007;
//	    if (k>k2) {
//	    	System.out.println("NO");
//	    } else {
//	    	System.out.println("YES");
//	    }
	    System.out.println(a);
	}

	// 文字列として入力を取得
	public static String gs() {
		return scanner.next();
	}

	// intとして入力を取得
	public static int gi() {
		return Integer.parseInt(scanner.next());
	}

	// longとして入力を取得
	public static long gl() {
		return Long.parseLong(scanner.next());
	}

	// doubleとして入力を取得
	public static double gd() {
		return Double.parseDouble(scanner.next());
	}
}
