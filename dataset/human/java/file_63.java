import java.util.Scanner;

public class Main {
	static String toChange(String s) {
		boolean isM = (s.charAt(0) == '1')?true:false;
		Long integerPart = 0L;
		Long decimalPart = 0L;
		for(int i = 1; i < 24; i++) {
			if(s.charAt(i) == '1') {
				long tmp = 1;
				for(int j = 0; j < 24-i; j++) {
					tmp *= 2L;
				}
				integerPart += tmp;
			}
		}
		if(s.charAt(24) == '1') {
			integerPart += 1;
		}
		if(s.charAt(25) == '1') {
			decimalPart += 5000000;
		}
		if(s.charAt(26) == '1') {
			decimalPart += 2500000;
		}
		if(s.charAt(27) == '1') {
			decimalPart += 1250000;
		}
		if(s.charAt(28) == '1') {
			decimalPart += 625000;
		}
		if(s.charAt(29) == '1') {
			decimalPart += 312500;
		}
		if(s.charAt(30) == '1') {
			decimalPart += 156250;
		}
		if(s.charAt(31) == '1') {
			decimalPart += 78125;
		}
		int decLen = decimalPart.toString().length();
		if(decimalPart != 0) {
			
			while(true) {
				if((Long.toString(decimalPart).charAt(Long.toString(decimalPart).length()-1) == '0')) {
					decimalPart /= 10;
				}
				else {
					break;
				}
			}
		}
		String tmp0 = integerPart.toString();
		String tmp1 = decimalPart.toString();
		if(decimalPart != 0) {
			for(int i = decLen; i < 7; i++) {
				tmp1 = "0" + tmp1;
			}
		}
		if(isM) {
			tmp0 = "-" + tmp0;
		}
		
		String tmp2 = "." + tmp1;
		tmp0 += tmp2;
		
		return tmp0;
	}
	
	static String toBin(String s) {
		String ans = "";
		for(int i = 0; i < 8; i++) {
			char tmp = s.charAt(i);
			if(tmp == '0') {
				ans += "0000";
				continue;
			}
			if(tmp == '1') {
				ans += "0001";
				continue;
			}
			if(tmp == '2') {
				ans += "0010";
				continue;
			}
			if(tmp == '3') {
				ans += "0011";
				continue;
			}
			if(tmp == '4') {
				ans += "0100";
				continue;
			}
			if(tmp == '5') {
				ans += "0101";
				continue;
			}
			if(tmp == '6') {
				ans += "0110";
				continue;
			}
			if(tmp == '7') {
				ans += "0111";
				continue;
			}
			if(tmp == '8') {
				ans += "1000";
				continue;
			}
			if(tmp == '9') {
				ans += "1001";
				continue;
			}
			if(tmp == 'a') {
				ans += "1010";
				continue;
			}
			if(tmp == 'b') {
				ans += "1011";
				continue;
			}
			if(tmp == 'c') {
				ans += "1100";
				continue;
			}
			if(tmp == 'd') {
				ans += "1101";
				continue;
			}
			if(tmp == 'e') {
				ans += "1110";
				continue;
			}
			if(tmp == 'f') {
				ans += "1111";
				continue;
			}
			
			
		}
		return ans;
	}

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int Q = stdIn.nextInt();
		for(int i = 0; i < Q; i++) {
			String s = stdIn.next();
			s = toBin(s);
			System.out.println(toChange(s));
		}
	}
}
