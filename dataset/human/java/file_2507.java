import java.util.Scanner;

public class Main {
	static int check(char[] str) {
		int sum = 0;
		int temp = 1;
		for(int i=0; i<str.length; i++) {
			if(Character.isDigit(str[i])) {
				temp = Character.getNumericValue(str[i]);
			}
			switch (str[i]) {
			case 'm':
				sum += 1000 * temp;
				temp = 1;
				break;
			case 'c':
				sum += 100 * temp;
				temp = 1;
				break;
			case 'x':
				sum += 10 * temp;
				temp = 1;
				break;
			case 'i':
				sum += 1 * temp;
				temp = 1;
				break;
			}

		}
		return sum;
	}
	static String toStr(int sum) {
		String str = "";
		if(sum/1000 != 0) {
			int a = sum/1000;
			if(a==1) {
				str += "m";
			}else {
				str += a + "m";
			}
			sum -= 1000*a;
		}if(sum/100 != 0) {
			int a = sum/100;
			if(a == 1) {
				str += "c";
			}else {
				str += a + "c";
			}
			sum -= 100*a;
		}if(sum/10 != 0) {
			int a = sum / 10;
			if(a == 1) {
				str += "x";
			}else {
				str += a + "x";
			}
			sum -= 10*a;
		}if(sum != 0) {
			if(sum == 1) {
				str += "i";
			}else {
				str += sum + "i";
			}
		}
		
		
		return str;
	}
	public static void main(String[] args) {
		try(Scanner sc = new Scanner(System.in)) {
			int n = sc.nextInt();
			for(int i=0; i<n; i++) {
				String s1 = sc.next();
				String s2 = sc.next();
				char[] str1 = new char[s1.length()];
				char[] str2 = new char[s2.length()];
				str1 = s1.toCharArray();
				str2 = s2.toCharArray();
				
				int sum = check(str1) + check(str2);
				
				System.out.println(toStr(sum));
				
				
				
				
				
			}
			
			
				
		}
	}
}
