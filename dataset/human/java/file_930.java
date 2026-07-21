import java.util.Scanner;
 
public class Main {
 
	static Scanner scanner;
 
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);
 
	    int n=gi();
	    int r=gi();
	    //int c=gi();
 
	    //System.out.print(String.valueOf(c));
 
        if (n>=10) {
        	System.out.print(r);
        }else {
        	System.out.print(r+(100*(10-n)));
        }
 
 
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
