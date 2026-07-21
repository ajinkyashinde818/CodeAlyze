import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String S = scan.next();

		if(S.equals("abc")|S.equals("acb")|S.equals("bac")|
				S.equals("bca")|S.equals("cab")|S.equals("cba")) {
		System.out.println("Yes");
		}else {
			System.out.println("No");

		}




	}

}
