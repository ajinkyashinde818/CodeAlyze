import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long n = Long.parseLong(sc.next());
		if(n%2==0) {
			System.out.println(f5(n/2));
		}else {
			System.out.println(0);
		}
	}

	public static long f5(long n) {
		if(n<5) {
			return 0;
		}else{
			return n/5+f5(n/5);
		}
	}
}
