import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String str_x = scan.next();
		String str_y = scan.next();
		int x = 0;
		int y = 0;
		
		if(str_x.equals("A")) {
			x = 10;
		} else if(str_x.equals("B")) {
			x = 11;
		} else if(str_x.equals("C")) {
			x = 12;
		} else if(str_x.equals("D")) {
			x = 13;
		} else if(str_x.equals("E")) {
			x = 14;
		} else if(str_x.equals("F")) {
			x = 15;
		}
		if(str_y.equals("A")) {
			y = 10;
		} else if(str_y.equals("B")) {
			y = 11;
		} else if(str_y.equals("C")) {
			y = 12;
		} else if(str_y.equals("D")) {
			y = 13;
		} else if(str_y.equals("E")) {
			y = 14;
		} else if(str_y.equals("F")) {
			y = 15;
		}
		if(x > y) {
			System.out.println(">");
		} else if(x < y) {
			System.out.println("<");
		} else {
			System.out.println("=");
		}
	}
}
