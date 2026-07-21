import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		for(int i=0;i<n;i++) {
			int a = mcxiToInteger(sc.next());
			int b = mcxiToInteger(sc.next());
			System.out.println(integerToMcxi(a+b));
		}
	}
	
	public static int mcxiToInteger(String s) {
		int n = 1;
		int ret = 0;
		for(int i=0;i<s.length();i++) {
			char c = s.charAt(i);
			if ('0' <= c && c <= '9') {
				n = c - '0';
			}else{
				switch (c) {
				case 'm':
					ret += n * 1000;
					break;
				case 'c':
					ret += n * 100;
					break;
				case 'x':
					ret += n * 10;
					break;
				case 'i':
					ret += n;
					break;
				}
				n = 1;
			}
		}
		return ret;
	}
	
	static char[] mcxi = {'m','c','x','i'};
	public static String integerToMcxi(int n) {
		StringBuilder sb = new StringBuilder();
		int m = 1000;
		for(int i=0;i<4;i++) {
			int x = (n / m) % 10;
			if (x >= 2) {
				sb.append(x);
			}
			if (x >= 1) {
				sb.append(mcxi[i]);
			}
			m /= 10;
		}
		return sb.toString();
	}

}
