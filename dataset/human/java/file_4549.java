import java.util.Scanner;

public class Main {

	static Scanner scanner;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    long a=gl();
	    long b=gl();
	    long c=gl();
	    long d=Math.min(a+b+1,c);
	    d+=b;
//	    if (k>k2) {
//	    	System.out.println("NO");
//	    } else {
//	    	System.out.println("YES");
//	    }
	    System.out.println(d);
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
