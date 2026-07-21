import java.util.*;

public class Main{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		long A = sc.nextInt();
		long B = sc.nextInt();
		long temp = Math.min(A, B);
		A = Math.max(A, B);
		B = temp;
		
		long result = A * B;
		
		long gcd = B;
		while(gcd != 0){
			gcd = A % B;
			A = B;
			B = gcd;
		}
		gcd = A;
		
		System.out.println(result/A);
	}
}
