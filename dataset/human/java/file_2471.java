import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int n = stdIn.nextInt();
		for(int i = 0; i < n; i++) {
			String a1 = stdIn.next();
			String a2 = stdIn.next();
			int b1 = toDec(a1);
			int b2 = toDec(a2);
			String ans = toMCXI(b1 + b2);
			
			System.out.println(ans);
		}
	}
	public static int toDec(String a) {
		int op = 1;
		int ans = 0;
		for(int i = 0; i < a.length(); i++) {
			if(a.charAt(i) == 'm') {
				ans += op * 1000;
				op = 1;
			}
			else if(a.charAt(i) == 'c') {
				ans += op * 100;
				op = 1;
			}
			else if(a.charAt(i) == 'x') { 
				ans += op * 10;
				op = 1;
			}
			else if(a.charAt(i) == 'i') {
				ans += op * 1;
				op = 1;
			}
			else {
				op = Integer.parseInt(String.valueOf(a.charAt(i)));
			}
		}
		return ans;
	}
	
	public static String toMCXI(int a) {
		String ans = "";
		if(a/1000 == 1) {
			ans += "m";
			a -= 1000;
		}
		if(a/1000 != 0){
			ans += a/1000+"m";
			a -= a/1000*1000;
		}
		if(a/100 == 1) {
			ans += "c";
			a -= 100;
		}
		if(a/100 != 0) {
			ans += a/100+"c";
			a -= a/100 * 100;
		}
		
		if(a / 10 == 1) {
			ans += "x";
			a -= 10;
		}
		if(a/10 != 0) {
			ans += a/10+"x";
			a -= a/10 * 10;
		}
		
		if(a == 1) {
			ans += "i";
			a -= 1;
		}
		if(a != 0) {
			ans += a+"i";
			a-= a;
		}
		
		return ans;
	}
}
