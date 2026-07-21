import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner stdIn = new Scanner(System.in);
		
		String X = stdIn.next();
		String Y = stdIn.next();
		
		if(X.charAt(0) > Y.charAt(0))
		{
			System.out.println(">");
		}
		else if(X.charAt(0) < Y.charAt(0))
		{
			System.out.println("<");
		}
		else
		{
			System.out.println("=");
		}
		
		

	}

}
