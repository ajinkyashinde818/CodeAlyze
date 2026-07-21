import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.nextLine();
		char x = s.charAt(0);
		char y = s.charAt(2);
		if(x > y){
			System.out.println(">");
		}else if(x == y){
			System.out.println("=");
		}else{
			System.out.println("<");
		}
	}
}
