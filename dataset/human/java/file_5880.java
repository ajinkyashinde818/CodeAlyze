import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String str = s.next();
		StringBuilder sb = new StringBuilder(str);
		/*		int N = s.nextInt();
		*/
		int a = -1;
		int b = -1;
		int c = -1;

		if (str.contains("a")) {
			if (str.contains("b")) {
				if (str.contains("c")) {
					System.out.println("Yes");
				}else{
					System.out.println("No");
				}
			}else{
				System.out.println("No");
			}
		}else{
			System.out.println("No");
		}


	}
}
