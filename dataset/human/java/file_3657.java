import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x = sc.next();
		String y = sc.next();
		sc.close();

		//compareToを用いた文字列比較
		if(x.compareTo(y) < 0) {
			System.out.println("<");
		}else if(x.compareTo(y) > 0) {
			System.out.println(">");
		}else if(x.compareTo(y) == 0){
			System.out.println("=");
		}

	}
}
