import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char a = sc.next().charAt(0);
		char b = sc.next().charAt(0);
		if(a > b)System.out.println(">");
		else if(a < b)System.out.println("<");
		else System.out.println("=");
	}
}
