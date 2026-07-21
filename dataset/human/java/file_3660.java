import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String t = sc.next();
		//long n = sc.nextLong();
		//long m = sc.nextLong();
		//long k = sc.nextLong();

		if(s.compareTo(t)<0) {
			System.out.println("<");
		}else if(s.compareTo(t)>0){
			System.out.println(">");
		}else {
			System.out.println("=");
		}
		//System.out.println(s.compareTo(t));
	}
}
