import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		long n = sc.nextLong();
		
		if(n % 2 == 1) {
			System.out.println(0);
			return;
		}

		long numOfTwo = n / 2;
		long numOfFive = 0;
		
		long fives = 5;
		while(true) {
//			System.out.println("1 divid by "+ fives);
			long tmp = n / 2 / fives;
			
			if(tmp == 0) {
				break;
			}
			
			numOfFive += tmp;
			fives *= 5;
		}
		
		long twos = 2;
		while(true) {
//			System.out.println("2 divid by "+ twos);
			long tmp = n / 2 / twos;
			
			if(tmp == 0) {
				break;
			}
			
			numOfTwo += tmp;
			twos *= 2;
		}
//		System.out.println(numOfTwo + " " + numOfFive);
		
		System.out.println(Math.min(numOfFive, numOfTwo));
	}

}
