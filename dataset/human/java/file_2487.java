import java.util.Scanner;

public class Main {
	
	static int MCXI(char c) {
		if(c == 'm') return 3;
		if(c == 'c') return 2;
		if(c == 'x') return 1;
		else return 0;
	}
	
	static int change(String str) {
		char[] s = new char[str.length()];
		for(int i=0; i<str.length(); i++) {
			s[i] = str.charAt(str.length()-i-1);
		}
		
		int f = 0;
		int k = 0;
		int sum = 0;
		int[] K = {1, 10, 100, 1000};
		for(int i=0; i<str.length(); i++) {
			if(s[i]=='i' || s[i]=='x' || s[i]=='c' || s[i]=='m') {
				if(f>=1) {
					sum += k * 1;
					f = 0;
				}
				k = K[MCXI(s[i])];
				f++;
			}
			if('1'<=s[i] && s[i]<='9') {
				int sei = (int)s[i] - '0';
				sum += k * sei;
				f = 0;
			}
			if(i==str.length()-1 && f==1) {
				sum += k * 1;
			}
		}
		return sum;
	}
	
	static String rechange(int sum) {
		String ans = "";
		if(sum >= 1000) {
			if(sum/1000 >= 2) {
				ans += String.valueOf(sum/1000);
			}
			ans += "m";
			sum = sum % 1000;
		}
		if(sum>=100) {
			if(sum/100 >= 2) {
				ans += String.valueOf(sum/100);
			}
			ans += "c";
			sum = sum % 100;
		}
		if(sum>=10) {
			if(sum/10 >= 2) {
				ans += String.valueOf(sum/10);
			}
			ans += "x";
			sum = sum % 10;
		}
		if(sum>=2) {
			ans += String.valueOf(sum);
		}
		if(sum>=1) {
			ans += "i";
		}
		return ans;
	}
	
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			int sum = 0;
			while(sc.hasNext()) {
				int n = sc.nextInt();
				if(n == 0) break;
				
				for(int i=0; i<n; i++) {
					String s = sc.next();
					sum = change(s);
					s = sc.next();
					sum += change(s);
					
					System.out.println(rechange(sum));
				}
			}
		}
	}
}
