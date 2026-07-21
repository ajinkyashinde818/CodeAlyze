import java.util.Scanner;

public class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		//String s = sc.next();
	    long n = sc.nextLong();
		long n2 = sc.nextLong();
		System.out.println(n * n2 / gcd(n , n2));

	}
	 public static long gcd(long num1,long num2) {
	        if(num2 == 0) return num1;
	        else return gcd(num2 , num1 % num2 );
	 }
}
