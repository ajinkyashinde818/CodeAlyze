import java.util.Scanner;

public class Main {
	// 2-100
	public static String check(int x, int y) {
		
		return "";
	}
	public static void main(String args[]) {
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int count = 0;
		int vit = 0;
		while (n-- != 0) {
			int x = in.nextInt();
			int y = in.nextInt();
			
			if (x == y) {
				count++;
			}else {
				count=0;
			}
			if (count==3) {
				vit = 1;
			}
		}
		if (vit == 1) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}

	}

}
