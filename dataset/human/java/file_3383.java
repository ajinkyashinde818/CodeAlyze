import java.util.Scanner;

public class Main {

	public static void main(String[] args) {


		Scanner sc = new Scanner(System.in);

		String W = sc.next();

		if (W.contains("9")){
			System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
	}
}
