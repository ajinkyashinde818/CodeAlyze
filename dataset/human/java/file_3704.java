import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc =new Scanner(System.in);
		String X=sc.next();
		String Y=sc.next();
		int x=X.compareTo(Y);
		if(x<0)System.out.println("<");
		else if(x==0)System.out.println("=");
		else System.out.println(">");
	}
}
