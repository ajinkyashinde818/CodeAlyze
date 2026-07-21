import java.util.Scanner;

public class Main {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String str1 = sc.next();
		String str2 = sc.next();

		int a=Integer.parseInt(str1, 16);
		int b=Integer.parseInt(str2, 16);

		if(a<b)System.out.println("<");
		if(a==b)System.out.println("=");
		if(a>b)System.out.println(">");
	}
}
