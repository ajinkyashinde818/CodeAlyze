import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char[] X = sc.next().toCharArray();
		char[] Y = sc.next().toCharArray();
		
		if (X[0] > Y[0])
			System.out.println(">");
		else if (X[0] < Y[0])
			System.out.println("<");
		else if (X[0] == Y[0])
			System.out.println("=");
		
	}
}
