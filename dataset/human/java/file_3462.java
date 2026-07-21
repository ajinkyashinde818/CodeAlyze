import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		String x = scan.next();
		String y = scan.next();

		int numx  = Integer.parseInt(x, 16);
		int numy = Integer.parseInt(y, 16);
		
		if(numx<numy){
			System.out.println("<");
		}else if(numx>numy){
			System.out.println(">");
		}else{
			System.out.println("=");
		}

	}

}
