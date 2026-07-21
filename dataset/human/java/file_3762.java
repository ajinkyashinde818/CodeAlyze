import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String x, y;
		x = sc.next();
		y = sc.next();
		sc.close();
		int tmp = x.compareTo(y);
		if(tmp < 0)System.out.println("<");
		else if(tmp == 0)System.out.println("=");
		else System.out.println(">");
	}

}
