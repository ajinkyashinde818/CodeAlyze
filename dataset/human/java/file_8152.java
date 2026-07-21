import java.util.Scanner;
public class Main {
	static long lcm(int a, int b) {
		int temp;
		long c = a;
		c *= b;
		while((temp = a%b) != 0) {
			a = b;
			b = temp;
		}
		return c/b;
	}
	
	
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		int a = stdIn.nextInt();
		int b = stdIn.nextInt();
		
		System.out.println(lcm(a,b));
		
		
		
		
		
		
		
	}

}
