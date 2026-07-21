import java.util.*;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char x = sc.next().charAt(0);
		char y = sc.next().charAt(0);
		int X = 10;
		int Y = 10;
		switch (x) {
		case 'B' :
			X = 11;
			break;
		case 'C' :
			X = 12;
			break;
		case 'D' :
			X = 13;
			break;
		case 'E' :
			X = 14;
			break;
		case 'F' :
			X = 15;
		}
		switch (y) {
		case 'B' :
			Y = 11;
			break;
		case 'C' :
			Y = 12;
			break;
		case 'D' :
			Y = 13;
			break;
		case 'E' :
			Y = 14;
			break;
		case 'F' :
			Y = 15;
		}
		if (X > Y) {
			System.out.println(">");
		}else if (X == Y) {
			System.out.println("=");
		}else if(X < Y) {
			System.out.println("<");
		}
	}
}
