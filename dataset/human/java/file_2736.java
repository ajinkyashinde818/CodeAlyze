import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        char[] SD = S.toCharArray();
        Arrays.sort(SD);
        char[] TD = T.toCharArray();
        Arrays.sort(TD);
        
        String SS = new String(SD);
        String TS = new String(TD);
        String RTS = new StringBuilder(TS).reverse().toString();        

		if(SS.compareTo(RTS) < 0) {
			System.out.print("Yes");
		} else {
			System.out.println("No");
	    }
	}
}
