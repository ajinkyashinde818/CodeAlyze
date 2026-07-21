import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		String word = sc.next();
		for(int i = word.length(); i >=0;) {
			if(i - 5 < 0) {
				System.out.println("NO");
				return;
			}
			if(word.substring(i-5,i).equals("dream") || word.substring(i-5,i).equals("erase")) {
				i -= 5;
				if(i == 0) {
					System.out.println("YES");
					return;
				}else {
					continue;
				}
			}
			if(i - 6 < 0) {
				System.out.println("NO");
				return;
			}
			if(word.substring(i-6,i).equals("eraser")) {
				i -= 6;
				if(i == 0) {
					System.out.println("YES");
					return;
				}else {
					continue;
				}
			}
			if(i - 7 < 0) {
				System.out.println("NO");
				return;
			}
			if(word.substring(i-7,i).equals("dreamer")) {
				i -= 7;
				if(i == 0) {
					System.out.println("YES");
					return;
				}else {
					continue;
				}
			}else {
				System.out.println("NO");
				return;
			}
		}
	}
}
