import java.util.*;

public class Main {
	public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
		String s = sc.next();
		boolean a = false;
		boolean b = false;
		boolean c = false;

		for (int i = 0; i < s.length(); i++) {
			switch (s.charAt(i)) {
				case 'a':
					a = true;
					break;
				case 'b':
					b = true;
					break;
				case 'c':
					c = true;
					break;
				default:
					break;
			}
		}

		if (a && b && c) {
    	System.out.println("Yes");
		} else {
			System.out.println("No");
		}
  }
}
