import java.util.*;

class Main {

	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		for(int i=0; i<n; i++){
			String s1 = in.next(), s2 = in.next();
			System.out.println(toString(toInt(s1) + toInt(s2)));
		}
	}

	private static int toInt(String str){
		int deg = 1, ans = 0;
		for(int i=0; i<str.length(); i++){
			char c = str.charAt(i);
			if(Character.isDigit(c)){
				deg = c - '0';
			}
			else{
				switch(c){
					case 'm':
						ans += deg*1000;
						break;
					case 'c':
						ans += deg*100;
						break;
					case 'x':
						ans += deg*10;
						break;
					case 'i':
						ans += deg;
						break;
				}
				deg = 1;
			}
		}
		return ans;
	}

	private static String toString(int n){
		StringBuffer str = new StringBuffer();
		for(int d=1000; d>=1; d/=10){
			int deg = (n/d)%10;
			if(deg > 1)
				str.append((char)(deg + '0'));
			if(deg > 0){
				switch(d){
				case 1000:
					str.append('m');
					break;
				case 100:
					str.append('c');
					break;
				case 10:
					str.append('x');
					break;
				case 1:
					str.append('i');
					break;
				}
			}
		}
		return str.toString();
	}

}
