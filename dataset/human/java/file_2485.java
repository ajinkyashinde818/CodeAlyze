import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int n = Integer.parseInt(sc.nextLine());
		for(int i = 0; i < n; i++) {
			String s = sc.nextLine();
			String[] sp = s.split("\\s+");
			
			int sum = num(sp[0]) + num(sp[1]);
			System.out.println(str(sum));
		}
		
	}
	
	public static int num(String s) {
		int pos = 0, sum = 0;
		
		while(pos < s.length()) {
			int multi = 0;
			switch(s.charAt(pos)) {
			case 'm': sum += 1000; pos++; break;
			case 'c': sum += 100; pos++; break;
			case 'x': sum += 10; pos++; break;
			case 'i': sum += 1; pos++; break;
			default:
				multi = s.charAt(pos++) - '0';
				if(pos < s.length()) {
					switch(s.charAt(pos++)) {
					case 'm': multi *= 1000; sum += multi; break;
					case 'c': multi *= 100; sum += multi; break;
					case 'x': multi *= 10; sum += multi; break;
					case 'i': sum += multi; break;
					default: sum += multi; break;
					}
				}
				break;
			}
		}
		
		return sum;
	}

	public static String str(int num) {
		String s = "";

		int m = num / 1000;
		if(m > 0) {
			if(m == 1) {
				s += 'm';
			}else {
				s += Integer.toString(m) + 'm';
			}
		}
		int c = (num % 1000) / 100;
		if(c > 0) {
			if(c == 1) {
				s += 'c';
			} else {
				s += Integer.toString(c) + 'c';
			}
		}
		int x = (num % 1000) % 100 / 10;
		if(x > 0) {
			if(x == 1) {
				s += 'x';
			}else {
				s += Integer.toString(x) + 'x';
			}
		}
		int i = (num % 1000) % 100 % 10 / 1;
		if(i > 0) {
			if(i == 1) {
				s += 'i';
			}else {
				s += Integer.toString(i) + 'i';
			}
		}
		
		return s;
	}
	
}
