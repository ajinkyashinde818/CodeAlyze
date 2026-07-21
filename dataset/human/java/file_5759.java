import java.util.Scanner;

public class Main{
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String s = scanner.next();
		scanner.close();
		int x = 0;
		int y = 0;
		int z = 0;
		for(int i = 0; i < 3; i++) {
			char c = s.charAt(i);
			if(c == 'a') {
				x ++;
			}else if(c == 'b') {
				y ++;
			}else if(c == 'c') {
				z ++;
			}
		}
		if(x == 1 && y == 1 && z == 1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}
}
