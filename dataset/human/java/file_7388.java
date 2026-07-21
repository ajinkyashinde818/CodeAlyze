import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String S = sc.next();
		S = new StringBuffer(S).reverse().toString();
		String[] keys = {"dream", "dreamer", "erase", "eraser"};
		boolean can = true;
		for (int i=0; i<S.length();) {
			boolean can2 = false;
			for (int j=0; j<4; j++) {
				String key = keys[j];
				key = new StringBuffer(key).reverse().toString();
				if ( i+key.length() > S.length() ) continue;
				if ( (S.substring(i, i+key.length())).equals(key) ){
					can2 = true;
					i+=key.length();
				}
			}
			if ( !can2 ) {
				can = false;
				break;
			}
		}
		if (can) System.out.println("YES");
		else System.out.println("NO");
	}
}
