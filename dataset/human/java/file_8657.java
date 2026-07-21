import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt();
		int B = sc.nextInt();
		int K = sc.nextInt();
		
		int c = gcd(A,B);
		int temp = c;
		while (K!=0){
			if (c%temp==0)
				K--;
			temp--;
			
		}
		System.out.println(temp+1);
		sc.close();

	}
	static int gcd(int m,int n) {
		if (m<n) {
			return gcd(n,m);
		}
		if (n==0) {
			return m;
		}
		return gcd(n,m%n);
	}
}
