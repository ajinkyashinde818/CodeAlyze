import java.util.*;

public class Main{
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	String S = sc.next();
	for ( int i = 0; i < S.length()-8; i++ ) {
	    System.out.print(S.charAt(i));
	}
	System.out.println();
    }
}
