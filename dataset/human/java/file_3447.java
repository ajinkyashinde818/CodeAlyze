import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		String n = scan.next();
		if(n.contains("9")) {
			System.out.println("Yes");
		}else {
			System.out.println("No");
		}
	}

}
