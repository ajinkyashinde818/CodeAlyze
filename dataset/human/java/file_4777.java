import java.util.Scanner;

class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		long N = sc.nextLong();
		long count = 0;
		long countIncrease = 0;
		
		if(N%2==1) {
			System.out.println(0);
			return;
		}

		for(long i = 10;i<=N;i *=5) {

			countIncrease = N/i;
			count += countIncrease;
		}
		System.out.println(count);
	}
		

}
