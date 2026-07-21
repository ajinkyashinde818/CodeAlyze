import java.util.*;

class Main {
	Scanner sc;
	
	private void calc() {
		sc = new Scanner(System.in);
		long N = sc.nextLong();
		if ( N%2 == 1) {
			System.out.println(0);
			return;
		}
		
		long n2 = N/2;
		long cnt5 = 0;
		while (n2 > 0) {
			cnt5 += (n2 = n2 / 5);
		}
		System.out.println(cnt5);
	}

	public static void main(String[] args) {
		new Main().calc();
	}
}
