import java.util.*;
public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int A = sc.nextInt(), B = sc.nextInt();
		sc.close();
		long ans = (long)A*B;
		long g = gcd(A, B);
		ans /= g;
		System.out.println(ans);
		
	}
	static long gcd(long x, long y) {
        return y==0? x : gcd(y,x%y);
    }
}
