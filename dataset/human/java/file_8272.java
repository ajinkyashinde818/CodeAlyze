import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		sc.close();
		System.out.println(A*B/GCD(A,B));
	}

	private static long GCD(long a, long b){
		if(a < b){
			return GCD(b,a);
		}
		if(b == 0){
			return a;
		}
		return GCD(b, a%b);
	}
}
