import java.util.Scanner;

class Main {
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		long A=Long.parseLong(sc.next());
		long B=Long.parseLong(sc.next());

		long C;
		if(A >= B) {
			C = getGcd(A,B);
		} else {
			C = getGcd(B, A);
		}
		long ans = (A*B)/C;
		System.out.println(ans);

	}

	public static long getGcd(long a , long b) {
		long c ;
		while(true) {
			c = b;
			if(a%b ==0) {
				return b;
			}
			b = a%b;
			a = c;
		}

	}
}
