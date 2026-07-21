import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String str = scan.nextLine();
		String[] array = str.split(" ");
		char X = array[0].charAt(0);
		char Y = array[1].charAt(0);

		char ans = '=';
		if(X < Y)
			ans = '<';
		if(X > Y)
			ans = '>';
		System.out.println(ans);
	}


}
