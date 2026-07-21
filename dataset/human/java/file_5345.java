import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		@SuppressWarnings("resource")
		Scanner scan = new Scanner(System.in);
		int A = scan.nextInt();

		if(A >= 1200){
			System.out.println("ARC");
		} else if (A < 1200) {
			System.out.println("ABC");			
		}			

	}

}
