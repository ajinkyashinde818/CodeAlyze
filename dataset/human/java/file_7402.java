import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String S = scan.nextLine();
		int cnt = 0;
		
		boolean kai = true;
		
		while (S.length() > 0) {
			
			if (S.endsWith("dream")) {
				S =  new String(S.substring(0,S.length() - 5));
			} else if (S.endsWith("dreamer")) {
				S = new String(S.substring(0,S.length() - 7));
			} else if (S.endsWith("erase")) {
				S = new String(S.substring(0,S.length() - 5));
			} else if (S.endsWith("eraser")) {
				S = new String(S.substring(0,S.length() - 6));
			} else {
				kai = false;
				break;
			}
			
			if (cnt % 1000 == 0) {
				System.gc();
			}
			
			cnt++;
			
		}
		
		System.gc();
		
		if (kai == true) {
			System.out.println("YES");
		} else {
			System.out.println("NO");
		}
		 
		 scan.close();

	}
}
