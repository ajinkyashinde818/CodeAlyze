import java.util.Scanner;

public class Main {
	static int[] mcxi = {1,10,100,1000};
	
	static int kchange(char a) {
		if(a=='m')return 3;
		if(a=='c')return 2;
		if(a=='x')return 1;
		else return 0;
	}
	
	static String rechange(int sum) {
		String ans = "";
		if(sum>=1000) {
			if(sum/1000>=2)
				ans += String.valueOf(sum/1000);
			ans += "m";
			sum = sum%1000;
		}
		if(sum>=100) {
			if(sum/100>=2)
				ans += String.valueOf(sum/100);
			ans += "c";
			sum = sum%100;
		}
		if(sum>=10) {
			if(sum/10>=2)
				ans += String.valueOf(sum/10);
			ans += "x";
			sum = sum%10;
		}
		if(sum>=2)
			ans += String.valueOf(sum);
		if(sum>=1)
			ans += "i";
	
		return ans;
	}
	
	static int change(String str) {
		char[] s = new char[str.length()];
		for(int j=0;j<str.length();j++) {
			s[j] = str.charAt(str.length()-j-1);
		}
					
		int sum = 0;
		int m = 0;
		int keta = 0;
		int b = 0;
		for(int j=0;j<str.length();j++) {
			if(s[j]=='i' || s[j]=='x' || s[j]=='c' || s[j] == 'm') {
				if(b>=1) {
					sum += keta*1;
					b = 0;
				}
				keta = mcxi[kchange(s[j])];
				b++;
				
			}
			if('1'<= s[j] && s[j] <= '9') {
				int g = (int)s[j]-'0';
				sum += keta*g;
				b = 0;
			}
			if(j==str.length()-1 && b==1)
				sum += keta*1;
		}
		return sum;
	}
	
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)){
			int sum = 0;
			while(sc.hasNext()) {
				int n=sc.nextInt();
				if(n==0) break;
				
				for(int i=0;i<n;i++) {
					String str = sc.next();
					sum = change(str);
					str = sc.next();
					sum += change(str);
					
					System.out.println(rechange(sum));
				}
			}
		}
	}
}
