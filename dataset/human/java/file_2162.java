import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {

			long n = sc.nextLong();

			//root nまでの素数を列挙
			List<Integer> factorPrimes = findPrimes((int)Math.sqrt(n)+1);
			
//			for(int p : factorPrimes) {
//				System.out.println(p);
//			}
			
			int count = 0;
			while( factorPrimes.size() > 0 ) {
				//find smallest prime number
				long p = factorPrimes.remove(0);
				
				if ( n % p == 0 ) {
					//bingo
					int pCount = 1;
					n = n / p;
					while (n % p == 0 ) {
						pCount++;
						n = n /p;
					}
					
					for(int i = 1 ; i <= pCount; i++ ) {
						if ( i <= pCount ) {
							count++;
							pCount -= i;
						}
					}
					
//					System.out.println(p);
//					System.out.println(count);
//					count += pCount;
				}
			}
			
			if ( n > 1 ) {
				//it is prime number;
				count++;
			}
			System.out.println(count);
		}
	}

	public static List<Integer> findPrimes(int n) {

		long[] primeCandidate = new long[n+1];

		List<Integer> primes = new ArrayList<>();

		for(int i = 2 ; i < n+1 ; i++ ) {
			if ( primeCandidate[i] == 0 ) {
				primes.add(i);
				int po = i*2;
				while (po <= n ) {
					primeCandidate[po] = 1;
					po += i;
				}
			}
		}
		
		return primes;

	}
}
