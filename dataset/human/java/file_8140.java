import java.util.Scanner;

 
public class Main {
 
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		long a = sc.nextLong();
		long b = sc.nextLong();

		long temp;
		long c = a;
		c *= b;
		while((temp = a%b) != 0) {
			a = b;
			b = temp;
		}
			
		System.out.print(c / b);
		sc.close();
	}
}
