import java.util.Scanner;

public class Main {

	static Scanner scanner;
	public static void main(String[] args) {
	    scanner = new Scanner(System.in);

	    long n=gl();
	    //long t=gl();
	    //int b=gi();


       // System.out.println(Math.max(x-t,0));
        if (n%10==9 || n>=90 ) {
        	System.out.print("Yes");
        }else {
            System.out.print("No");
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
}
