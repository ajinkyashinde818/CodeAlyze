import java.util.Scanner;
class Main {
	
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long A = sc.nextInt();
        long B = sc.nextInt();
        System.out.println(A*B/gcd(A,B));
    }
    static long gcd(long m, long n) {
    		if(m < n) return gcd(n,m);
    		if(n == 0) return m;
    		return gcd(n, m%n);
    }
}
