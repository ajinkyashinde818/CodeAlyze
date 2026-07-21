import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		
		Scanner stdIn = new Scanner(System.in);
		
		String input = stdIn.next();
		if(input.indexOf("9") >= 0) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}

	}
}
