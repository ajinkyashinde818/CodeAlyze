import java.util.Scanner;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String a = sc.next();
		String b = sc.next();
		
		byte[] b1 = a.getBytes();
		byte[] b2 = b.getBytes();
		
//		System.out.println(b1[0]);
//		System.out.println(b2[0]);
		
		if (b1[0] > b2[0]){
			System.out.println(">");
		}
		else if (b1[0] < b2[0]){
			System.out.println("<");
		}
		else {
			System.out.println("=");
		}
	}

}
