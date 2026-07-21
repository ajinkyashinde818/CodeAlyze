import java.util.*;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int a = 0;
		int b = 0;
		int c = 0;
		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
				case 'a' :
				a++;
				break;
				case 'b' :
				b++;
				break;
				case 'c' :
				c++;
			}
		}
		if (a == 1 && b == 1 && c == 1) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
