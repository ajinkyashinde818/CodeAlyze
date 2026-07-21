import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		String x = scan.next();
		String y = scan.next();
		char xC = x.charAt(0);
		char xY = y.charAt(0);
		if(xC<xY) {
			System.out.println("<");
		}else if(xC>xY) {
			System.out.println(">");
		}else {
			System.out.println("=");
		}
	}

}
