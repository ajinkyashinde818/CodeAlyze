import java.util.Scanner;

public class Main {
	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		long a = Integer.parseInt(scan.next());
		long b = Integer.parseInt(scan.next());
		long mult = a * b;
		
		if(a < b) {
			long tmp = a;
			a = b;
			b = tmp;
		}
		
		long r = a % b;
		while(r > 0) {
			a = b;
			b = r;
			r = a % b;
		}
		
		System.out.println(mult / b);
		scan.close();
	}
}
