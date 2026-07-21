import java.util.Scanner;
 
public class Main {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String s1 = sc.next();
		if(s.compareTo(s1) == 0) {
			System.out.println("=");
		} else if(s.compareTo(s1) > 0) {
			System.out.println(">");
		} else {
			System.out.println("<");
		}
	}
}
