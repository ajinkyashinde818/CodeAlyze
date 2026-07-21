import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		sc.close();
		if(N < 2 || N % 2 == 1){
			System.out.println(fnika(N));
		}else{
			System.out.println(fnijou(N));
		}
	}

	private static long fnika(long n) {// n<2のとき
		return 0;
	}

	private static long fnijou(long n) {// n>=2のとき
		n /= 2;
		long baisu = 0;
		while(n!=0){
			baisu += n / 5;
			n /= 5;
		}
		return baisu;
	}
}
