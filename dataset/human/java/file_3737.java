import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		String s = "ABCDEF";
		Scanner scanner = new Scanner(System.in);
		String X = scanner.next(), Y = scanner.next();
		int x = s.indexOf(X),y = s.indexOf(Y);
		if(x < y){
			System.out.println("<");
		}else if(x > y){
			System.out.println(">");
		}else{
			System.out.println("=");
		}
	}

}
