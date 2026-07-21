import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner stdin = new Scanner(System.in);
		String a = stdin.next();
		String b = stdin.next();
		
		if(a.charAt(0)>b.charAt(0)) {
			System.out.println(">");
		}else if(a.charAt(0)==b.charAt(0)) {
			System.out.println("=");
		} else {
			System.out.println("<");
		}
		
		


	}

}
