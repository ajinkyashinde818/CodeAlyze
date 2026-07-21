import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		int a = Integer.parseInt(s,16);
		s = scan.next();
		int b = Integer.parseInt(s,16);
		if(a < b){
			System.out.println("<");
		}else if(a == b){
			System.out.println("=");
		}else{
			System.out.println(">");
		}
		scan.close();

	}

}
