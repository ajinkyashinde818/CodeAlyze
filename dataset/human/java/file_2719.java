import java.util.Arrays;
import java.util.Scanner;

public class Main {

	static Scanner scanner;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    String s=gs();
	    String t=gs();
	    //int a=gi();
	    //int b=gi();
	    char[] sc=s.toCharArray();
	    char[] tc=t.toCharArray();
	    Arrays.parallelSort(sc);
	    Arrays.parallelSort(tc);
	    s=String.valueOf(sc);
	    t=String.valueOf(tc);
	    StringBuffer tsb=new StringBuffer(t);
	    t=tsb.reverse().toString();

	    
	    //System.out.println(Math.floorDiv(a-1,2));
	    if (s.compareTo(t) <0) {
	    	System.out.print("Yes");
	    }else {
	    	System.out.print("No");
	    }



	}

	public static long d(long n) {
		String a=String.valueOf(n);
		return (long)a.length();
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
