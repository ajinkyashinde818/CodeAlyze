import java.util.*;

public class Main {

	static Scanner sc = new Scanner(System.in);
	static int n;
	static String s1, s2;
	static char[] c = {'m', 'c', 'x', 'i'};
	static int[] val = {1000, 100, 10, 1};
	
	static int parse(String str) {
		int ret = 0;
		for(int i = 0; i < 4; i++) {
			int pos = str.indexOf(c[i]);
			if (pos > 0 && Character.isDigit(str.charAt(pos - 1))) {
				ret += Integer.parseInt(str.substring(pos - 1, pos)) * val[i];
			} else if(pos >= 0) {
				ret += val[i];
			}
		}
		return ret;
	}
	
	static String unparse(int num) {
		String ret = "";
		for(int i = 0; i < 4; i++) {
			int num_ = num / val[i];
			if(num_ > 1) {
				ret += String.valueOf(num_) + c[i];
			} else if(num_ == 1) {
				ret += c[i];
			}
			
			num = num % val[i];
		}
		return ret;
	}
	
	public static void main(String[] args) {
		n = sc.nextInt();
		for(int i = 0; i < n; i++) {
			s1 = sc.next();
			s2 = sc.next();
			System.out.println(unparse(parse(s1) + parse(s2)));
		}
	}
}
