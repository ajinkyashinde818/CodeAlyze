import java.util.Scanner;

public class Main {
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			int A = scan.nextInt();
			int B = scan.nextInt();
			
			System.out.println(lcm((long)A,(long)B));
			
			
			
			
		}
		
		
	}
	
	
	private  static long lcm(long A,long B) {//最小公倍数
		return A*B/gcd(A,B);
	}
	
	private static long gcd(long A,long B){//最大公約数
		return B==0?A:gcd (B,A%B);
	}
	
		

}
