import java.util.*;
public class Main {
	static Scanner sc = new Scanner(System.in);
	static int n;
	static String str1, str2;
	public static void main(String[] args) {
		while(read()){
			
		}
	}
	
	static boolean read(){
		if(!sc.hasNext()) return false;
		n = sc.nextInt();
		for(int i = 0; i < n; i++){
			str1 = sc.next();
			str2 = sc.next();
			solve();
		}
		return true;
	}
	
	static void solve(){
		int sum = calc(str1) + calc(str2);
		System.out.println(restore(sum));
	}
	
	static int value(char letter){
		switch(letter){
		case 'm':
			return 1000;
		case 'c':
			return 100;
		case 'x':
			return 10;
		case 'i':
			return 1;
		default:
			return -100;
		}
	}
	static int calc(String str){
		int ret = 0;
		for(int i = 0; i < str.length(); i++){
			if(Character.isDigit(str.charAt(i))){
				StringBuffer sb = new StringBuffer(str.subSequence(i, i+2));
				int coefficient = sb.toString().charAt(0) - '0';//係数
				char type = sb.toString().charAt(1);
				ret += coefficient*value(type);
				i++;
			}else{
				StringBuffer sb = new StringBuffer(str.subSequence(i, i+1));
				char type = sb.toString().charAt(0);
				ret += value(type);
			}
		}
		return ret;
	}

	static String restore(int value){
		int residue = 0;
		int m = value / 1000;
		residue = value % 1000;
		int c = residue / 100;
		residue = residue % 100;
		int x = residue / 10;
		int i = residue % 10;
		String ret = "";
		if( m != 0 ){
			if( m == 1 ){
				ret += "m";
			}else{
				ret += Integer.toString(m)+"m";
			}
		}
		if( c != 0 ){
			if( c == 1 ){
				ret += "c";
			}else{
				ret += Integer.toString(c)+"c";
			}
		}
		if( x != 0 ){
			if( x == 1 ){
				ret += "x";
			}else{
				ret += Integer.toString(x)+"x";
			}
		}
		if( i != 0 ){
			if( i == 1 ){
				ret += "i";
			}else{
				ret += Integer.toString(i)+"i";
			}
		}
		return ret;
	}
}
