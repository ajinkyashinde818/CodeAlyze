import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ

		Scanner sc = new Scanner(System.in);
		int x= sc.nextInt();
		
		if(x%10==9||90<=x) {
		System.out.println("Yes");
		}
		else {
			System.out.println("No");
		}
		
	}
}
