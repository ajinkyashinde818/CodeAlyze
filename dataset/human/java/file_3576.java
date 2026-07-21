import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a = Integer.parseInt(sc.next(), 16);
		int b = Integer.parseInt(sc.next(), 16);

		if (a < b){
			System.out.println("<");
		}else if (a == b){
			System.out.println("=");
		}else {
			System.out.println(">");
		}
	}
}
