import java.util.Scanner;
 
class Main{
 
	public static void main(String[] args) {
		
		Scanner stdIn = new Scanner(System.in);
 
		int A = stdIn.nextInt();
		int B = stdIn.nextInt();
		int C;
		
		if (A <= 10) {
			C = B + (100 * (10 - A));
			System.out.println(C);
		}else{
			System.out.println(B);
		}
		
	
	}
}
